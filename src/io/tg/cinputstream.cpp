#include "cinputstream.h"

#include <QTextStream>
#include <QDebug>

#include "../../song/csong.h"

CInputStream::CInputStream()
    : CStream()
    , CInputStreamBase()
{
}

CInputStream::~CInputStream()
{
    delete m_data_stream;
}

void CInputStream::init(QDataStream *stream)
{
    delete m_data_stream;
    m_data_stream = stream;
    m_data_stream->setByteOrder(QDataStream::BigEndian);
    m_version.clear();
}

bool CInputStream::isSupportedVersion()
{
    try {
        readVersion();
        return isSupportedVersion(m_version);
    }
    catch( ... ) {
        return false;
    }
}

CSong* CInputStream::readSong()
{
    log_info("Song reading");

    if( isSupportedVersion() )
    {
        CSong* song = read();
        m_data_stream->device()->close();
        return song;
    }
    throw EXCEPTION("Unsupported file version");
}

void CInputStream::readVersion()
{
    if( m_version.isEmpty() )
    {
        log_debug("Reading version");
        m_version = readUnsignedByteString();
    }
}

CSong* CInputStream::read()
{
    CSong* song = new CSong();

    log_debug("Reading name");
    song->name(readUnsignedByteString());
    log_debug("Reading artist");
    song->artist(readUnsignedByteString());
    log_debug("Reading album");
    song->album(readUnsignedByteString());
    log_debug("Reading author");
    song->author(readUnsignedByteString());
    log_debug("Reading date");
    song->date(readUnsignedByteString());
    log_debug("Reading copyright");
    song->copyright(readUnsignedByteString());
    log_debug("Reading writer");
    song->writer(readUnsignedByteString());
    log_debug("Reading transcriber");
    song->transcriber(readUnsignedByteString());
    log_debug("Reading comments");
    song->comments(readIntegerString());

    log_debug("Reading channels");
    qint8 channel_count = readByte();
    for(qint8 i = 0; i < channel_count; i++)
    {
        log_debug("  channel %i", i);
        CChannel channel;
        readChannel(channel);
        song->channelAdd(channel);
    }

    log_debug("Reading measure headers");
    qint16 header_count = readShort();
    const CMeasureHeader *last_header = NULL;
    qint64 header_start = CDuration::QUARTER_TIME;
    for(qint16 i = 0; i < header_count; i++)
    {
        CMeasureHeader header;
        readMeasureHeader(header, i + 1, header_start, last_header);
        song->measureHeaderAdd(header);
        header_start += header.length();
        last_header = &(song->measureHeader(song->measureHeadersCount() - 1));
    }

    log_debug("Reading tracks");
    qint8 track_count = readByte();
    for(int i = 0; i < track_count; i++)
    {
        CTrack track;
        readTrack(i + 1, song, track);
        song->trackAdd(track);
    }

    return song;
}

void CInputStream::readChannel(CChannel& channel)
{
    log_debug("Reading channel id");
    channel.id(readShort());
    log_debug("Reading bank");
    channel.bank(readByte());
    log_debug("Reading program");
    channel.program(readByte());
    log_debug("Reading volume");
    channel.volume(readByte());
    log_debug("Reading balance");
    channel.balance(readByte());
    log_debug("Reading chorus");
    channel.chorus(readByte());
    log_debug("Reading reverb");
    channel.reverb(readByte());
    log_debug("Reading phaser");
    channel.phaser(readByte());
    log_debug("Reading tremolo");
    channel.tremolo(readByte());
    log_debug("Reading name");
    channel.name(readUnsignedByteString());

    readChannelParameters(channel);
}

void CInputStream::readChannelParameters(CChannel &channel)
{
    log_debug("Reading channel parameters");
    qint16 count = readShort();

    for( qint16 i = 0; i < count; i++ )
    {
        log_debug("Reading channel parameter %i", i);
        readChannelParameter(channel);
    }
}

void CInputStream::readChannelParameter(CChannel &channel)
{
    CChannelParameter parameter(readUnsignedByteString(), readIntegerString());
    channel.parameterAdd(parameter);
}

CMeasureHeader CInputStream::readMeasureHeader(CMeasureHeader &measure_header, qint32 number, qint64 start, const CMeasureHeader *last_header)
{
    quint32 header = readHeader();

    measure_header.number(number);
    measure_header.start(start);

    log_debug("Reading time signature");
    if( (header & MEASURE_HEADER_TIMESIGNATURE) != 0 )
    {
        CTimeSignature time_signature;
        readTimeSignature(time_signature);
        measure_header.timeSignature(time_signature);
    }
    else if( last_header != NULL )
        measure_header.timeSignature(last_header->timeSignature());

    throw EXCEPTION("Nomore!");

    log_debug("Reading tempo");
    if( (header & MEASURE_HEADER_TEMPO) != 0 )
    {
        CTempo tempo;
        readTempo(tempo);
        measure_header.tempo(tempo);
    }
    else if( last_header != NULL )
        measure_header.tempo(last_header->tempo());

    log_debug("Reading repeat open");
    measure_header.repeatOpen((header & MEASURE_HEADER_REPEAT_OPEN) != 0);

    log_debug("Reading repeat close");
    if( (header & MEASURE_HEADER_REPEAT_CLOSE) != 0 )
         measure_header.repeatClose(readShort());

    log_debug("Reading repeat alternative");
    if( (header & MEASURE_HEADER_REPEAT_ALTERNATIVE) != 0 )
         measure_header.repeatAlternative(readByte());

    log_debug("Reading marker");
    if( (header & MEASURE_HEADER_MARKER) != 0 )
    {
        CMarker marker;
        readMarker(number, marker);
        measure_header.marker(&marker);
    }

    log_debug("Reading triplet feel");
    if( (header & MEASURE_HEADER_TRIPLET_FEEL) != 0 )
        measure_header.tripletFeel(readByte());
    else
        measure_header.tripletFeel( (last_header != NULL) ? last_header->tripletFeel() : CMeasureHeader::TRIPLET_FEEL_NONE );

    return measure_header;
}

void CInputStream::readTempo(CTempo &tempo)
{
}

void CInputStream::readTrack(qint8 number, CSong *song, CTrack &track)
{
    log_debug("Reading track %i", number);

    log_debug("Reading header");
    qint32 header = readHeader();

    track.number(number);
    log_debug("Reading name");
    track.name(readUnsignedByteString());
    track.solo((header & TRACK_SOLO) != 0);
    track.mute((header & TRACK_MUTE) != 0);
    log_debug("Reading channel");
    track.channelId(readShort());

    log_debug("Reading measure headers");
    quint16 measure_count = song->measureHeadersCount();
    CMeasure *last_measure = NULL;
    for(quint16 i = 0; i < measure_count; i++)
    {
        track.measureAdd(readMeasure(song->measureHeader(i), last_measure));
        last_measure = &(track.measure(i));
    }
///////////////////////////////////////////
    /*
    //leo la cantidad de cuerdas
    int stringCount = readByte();

    //leo las cuerdas
    for(int i = 0;i < stringCount;i++){
        track.getStrings().add(readInstrumentString(i + 1));
    }

    //leo el offset
    track.setOffset(TGTrack.MIN_OFFSET + readByte());

    //leo el color
    readRGBColor(track.getColor());

    //leo el lyrics
    if(((header & TRACK_LYRICS) != 0)){
        readLyrics(track.getLyrics());
    }*/
}

CMeasure CInputStream::readMeasure(CMeasureHeader &measure_header, CMeasure *last_measure)
{
    qint32 header = readHeader();
    CMeasure measure(measure_header);
    CBeatData data(measure);

    log_debug("Reading beats");
    readBeats(measure, data);
////////////////////////////////
    /*
    measure.setClef( (lastMeasure == null)?TGMeasure.CLEF_TREBLE:lastMeasure.getClef());
    if(((header & MEASURE_CLEF) != 0)){
        measure.setClef(readByte());
    }

    //leo el key signature
    measure.setKeySignature((lastMeasure == null)?0:lastMeasure.getKeySignature());
    if(((header & MEASURE_KEYSIGNATURE) != 0)){
        measure.setKeySignature(readByte());
    }
*/
    return measure;
}

void CInputStream::readBeats(CMeasure &measure, CStream::CBeatData &data)
{
    qint32 header = BEAT_HAS_NEXT;
    while( (header & BEAT_HAS_NEXT) != 0 )
    {
        header = readHeader();
        readBeat(header, measure, data);
    }
}

void CInputStream::readBeat(quint32 header, CMeasure &measure, CStream::CBeatData &data)
{
    CBeat beat;

    beat.start(data.currentStart());

    readVoices(header, beat, data);
/////////////////////////////
    /*
    //leo el stroke
    if(((header & BEAT_HAS_STROKE) != 0)){
        readStroke(beat.getStroke());
    }

    //leo el acorde
    if(((header & BEAT_HAS_CHORD) != 0)){
        readChord(beat);
    }

    //leo el texto
    if(((header & BEAT_HAS_TEXT) != 0)){
        readText(beat);
    }*/

    measure.beatAdd(beat);
}

void CInputStream::readVoices(quint32 header, CBeat &beat, CStream::CBeatData &data)
{
    for( quint8 i = 0 ; i < CBeat::MAX_VOICES; i++ )
    {
        quint16 shift = i * 2;

        beat.voice(i).empty(true);
//////////////////////////
        /*
        if(((header & (BEAT_HAS_VOICE << shift)) != 0)){
            if(((header & (BEAT_HAS_VOICE_CHANGES << shift)) != 0)){
                data.getVoice(i).setFlags( readHeader() );
            }

            int flags = data.getVoice(i).getFlags();

            //leo la duracion
            if(((flags & VOICE_NEXT_DURATION) != 0)){
                readDuration(data.getVoice(i).getDuration());
            }

            //leo las notas
            if(((flags & VOICE_HAS_NOTES) != 0)){
                readNotes(beat.getVoice(i), data);
            }

            //leo la direccion
            if(((flags & VOICE_DIRECTION_UP) != 0)){
                beat.getVoice(i).setDirection( TGVoice.DIRECTION_UP );
            }
            else if(((flags & VOICE_DIRECTION_DOWN) != 0)){
                beat.getVoice(i).setDirection( TGVoice.DIRECTION_DOWN );
            }
            data.getVoice(i).getDuration().copy(beat.getVoice(i).getDuration());
            data.getVoice(i).setStart(data.getVoice(i).getStart() + beat.getVoice(i).getDuration().getTime());

            beat.getVoice(i).setEmpty(false);
        }*/
    }
}

void CInputStream::readTimeSignature(CTimeSignature &time_signature)
{
    log_debug("Reading numerator");
    time_signature.numerator(readByte());

    log_debug("Reading denominator");
    CDuration duration;
    readDuration(duration);
    time_signature.denominator(duration);
}

void CInputStream::readDuration(CDuration &duration)
{
    log_debug("Reading duration");
    qint32 header = readHeader();

    log_debug("Reading dotted");
    duration.dotted((header & DURATION_DOTTED) != 0);

    log_debug("Reading double dotted");
    duration.doubleDotted((header & DURATION_DOUBLE_DOTTED) != 0);

    log_debug("Reading value");
    duration.value(readByte());

    log_debug("Reading division type");
    if( (header & DURATION_NO_TUPLET) != 0 )
    {
        CDivisionType division;
        readDivisionType(division);
        duration.divisionType(division);
    }
    else
        duration.divisionType(CDivisionType::NORMAL);
}

void CInputStream::readDivisionType(CDivisionType &division)
{
    log_debug("Reading enter");
    division.enter(readByte());

    log_debug("Reading time");
    division.time(readByte());
}

qint32 CInputStream::readHeader()
{
    qint32 data;
    (*m_data_stream) >> data;
    log_debug("Reading header: %i", data);
    return data;
}

qint32 CInputStream::readHeader(qint32 count)
{
    qint32 header = 0;
    for(qint32 i = count; i > 0; i--)
        header += ( readHeader() << ( (8 * i) - 8 ) );

    return header;
}

qint8 CInputStream::readByte()
{
    qint8 data;
    (*m_data_stream) >> data;
    log_debug("Reading byte: %i", data);
    return data;
}

qint16 CInputStream::readShort()
{
    qint16 data;
    (*m_data_stream) >> data;
    log_debug("Reading short: %i", data);
    return data;
}

QString CInputStream::readUnsignedByteString()
{
    quint8 data;
    (*m_data_stream) >> data;
    log_debug("Reading byte length: %i", data);

    return data > 0 ? readString(data) : "";
}

QString CInputStream::readIntegerString()
{
    quint32 data;
    (*m_data_stream) >> data;
    log_debug("Reading integer length: %i, pos: %i", data, m_data_stream->device()->pos());

    return data > 0 ? readString(data) : "";
}

QString CInputStream::readString(quint64 length)
{
    QTextStream stream(m_data_stream->device());
    quint64 lastpos = m_data_stream->device()->pos();
    stream.setCodec("UTF-16BE");
    QString out = stream.read(length);
    stream.seek(lastpos + length * 2);

    log_debug("Finished reading '%1'", out);

    return out;
}

void CInputStream::readMarker(qint32 number, CMarker &marker)
{
}
