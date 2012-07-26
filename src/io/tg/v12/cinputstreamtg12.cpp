#include "cinputstreamtg12.h"

#include <QTextStream>
#include <QDebug>

#include "../../../song/csong.h"

CInputStreamTG12::CInputStreamTG12()
    : CStreamTG12()
    , CInputStreamBase()
{
}

CInputStreamTG12::~CInputStreamTG12()
{
    delete m_data_stream;
}

void CInputStreamTG12::init(QDataStream *stream)
{
    log_info("Initializing stream");
    m_data_stream = stream;
    m_data_stream->setByteOrder(QDataStream::BigEndian);
    m_version.clear();
}

bool CInputStreamTG12::isSupportedVersion()
{
    try {
        readVersion();
        return isSupportedVersion(m_version);
    }
    catch( ... ) {
        return false;
    }
}

CSong* CInputStreamTG12::readSong()
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

void CInputStreamTG12::readVersion()
{
    if( m_version.isEmpty() )
    {
        log_debug("Reading version");
        m_version = readUByteString();
    }
}

CSong* CInputStreamTG12::read()
{
    CSong* song = new CSong();

    log_debug("Reading name");
    song->name(readUByteString());
    log_debug("Reading artist");
    song->artist(readUByteString());
    log_debug("Reading album");
    song->album(readUByteString());
    log_debug("Reading author");
    song->author(readUByteString());
    log_debug("Reading date");
    song->date(readUByteString());
    log_debug("Reading copyright");
    song->copyright(readUByteString());
    log_debug("Reading writer");
    song->writer(readUByteString());
    log_debug("Reading transcriber");
    song->transcriber(readUByteString());
    log_debug("Reading comments");
    song->comments(readIntegerString());

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
        last_header = &(song->measureHeader(i));
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

void CInputStreamTG12::readChannel(CSong *song, CTrack &track)
{
    log_debug("Reading channel");

    CChannel channel;
    CChannelParameter gmChannel1Param;
    CChannelParameter gmChannel2Param;

    quint8 channel1 = readUByte();
    gmChannel1Param.key("1"); // TODO: get info
    gmChannel1Param.value(QString::number(channel1));

    quint8 channel2 = readUByte();
    gmChannel2Param.key("2"); // TODO: get info
    gmChannel2Param.value(QString::number(channel2));

    log_debug("Reading bank");
    channel.bank( channel1 == 9 ? 128 : CChannel::DEFAULT_BANK);
    log_debug("Reading program");
    channel.program(readUByte());
    log_debug("Reading volume");
    channel.volume(readUByte());
    log_debug("Reading balance");
    channel.balance(readUByte());
    log_debug("Reading chorus");
    channel.chorus(readUByte());
    log_debug("Reading reverb");
    channel.reverb(readUByte());
    log_debug("Reading phaser");
    channel.phaser(readUByte());
    log_debug("Reading tremolo");
    channel.tremolo(readUByte());

    for( quint8 i = 0; i < song->channelsCount(); i++ )
    {
        CChannel channel_aux = song->channel(i);
        for( int n = 0; n < channel_aux.parametersCount(); n++ )
        {
            CChannelParameter channel_parameter = channel_aux.parameter(n);
            if( channel_parameter.key() == "1" )
            {
                if( QString(channel1) == channel_parameter.value() )
                    channel.id(channel_aux.id());
            }
        }
    }

    if( channel.id() <= 0 )
    {
        channel.id(song->channelsCount() + 1);
        channel.name("#" + QString::number(channel.id()));
        channel.parameterAdd(gmChannel1Param);
        channel.parameterAdd(gmChannel2Param);
        song->channelAdd(channel);
    }

    track.channelId(channel.id());
}


void CInputStreamTG12::readMeasureHeader(CMeasureHeader &measure_header, qint32 number, qint64 start, const CMeasureHeader *last_header)
{
    log_debug("Reading measure header #%i", number);
    quint8 header = readUByte();

    measure_header.number(number);
    measure_header.start(start);

    if( (header & MEASURE_HEADER_TIMESIGNATURE) != 0 )
    {
        log_debug("Reading time signature");
        CTimeSignature time_signature;
        readTimeSignature(time_signature);
        measure_header.timeSignature(time_signature);
    }
    else if( last_header != NULL )
        measure_header.timeSignature(last_header->timeSignature());

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

    if( (header & MEASURE_HEADER_REPEAT_CLOSE) != 0 )
    {
        log_debug("Reading repeat close");
        measure_header.repeatClose(readShort());
    }

    if( (header & MEASURE_HEADER_REPEAT_ALTERNATIVE) != 0 )
    {
        log_debug("Reading repeat alternative");
        measure_header.repeatAlternative(readByte());
    }

    if( (header & MEASURE_HEADER_MARKER) != 0 )
    {
        log_debug("Found marker");
        CMarker marker;
        readMarker(number, marker);
        measure_header.marker(&marker);
    }

    log_debug("Reading triplet feel");
    if( (header & MEASURE_HEADER_TRIPLET_FEEL) != 0 )
        measure_header.tripletFeel(readByte());
    else
        measure_header.tripletFeel( (last_header != NULL) ? last_header->tripletFeel() : CMeasureHeader::TRIPLET_FEEL_NONE );
}

void CInputStreamTG12::readTempo(CTempo &tempo)
{
    log_debug("Reading tempo");
    tempo.value(readShort());
}

void CInputStreamTG12::readTrack(qint8 number, CSong *song, CTrack &track)
{
    log_debug("Reading track %i", number);

    log_debug("Reading track header");
    quint8 header = readUByte();

    track.number(number);
    log_debug("Reading track name");
    track.name(readUByteString());
    track.solo((header & TRACK_SOLO) != 0);
    track.mute((header & TRACK_MUTE) != 0);

    log_debug("Reading track channel");
    readChannel(song, track);

    log_debug("Reading track measures");
    quint16 measure_count = song->measureHeadersCount();
    CMeasure *last_measure = NULL;
    for(quint16 i = 0; i < measure_count; i++)
    {
        track.measureAdd(readMeasure(song->measureHeader(i), last_measure));
        last_measure = &(track.measure(i));
    }

    log_debug("Reading track strings count");
    qint8 string_count = readByte();

    for( int i = 0; i < string_count; i++ )
        track.stringAdd(readInstrumentString(i + 1));

    log_debug("Reading track offset");
    track.offset(CTrack::MIN_OFFSET + readByte());

    track.color(readRGBColor());

    if( (header & TRACK_LYRICS) != 0 )
        track.lyrics(readLyrics());
}

CMeasure CInputStreamTG12::readMeasure(CMeasureHeader &measure_header, CMeasure *last_measure)
{
    log_debug("Read measure");
    CMeasure measure(measure_header);
    quint8 header = readUByte();
    CBeatData data(measure);

    readBeats(measure, data);

    log_debug("Reading clef");
    if( (header & MEASURE_CLEF) != 0 )
        measure.clef(readByte());
    else
        measure.clef((last_measure == NULL) ? CMeasure::CLEF_TREBLE : last_measure->clef());

    log_debug("Reading key signature");
    if( (header & MEASURE_KEYSIGNATURE) != 0 )
        measure.keySignature(readByte());
    else
        measure.keySignature((last_measure == NULL) ? 0 : last_measure->keySignature());

    return measure;
}

void CInputStreamTG12::readBeats(CMeasure &measure, CStreamTG12::CBeatData &data)
{
    log_debug("Reading beats");
    quint8 header = BEAT_HAS_NEXT;
    do
    {
        log_debug("Reading header");
        header = readUByte();
        readBeat(header, measure, data);
    }
    while( (header & BEAT_HAS_NEXT) != 0 );
}

void CInputStreamTG12::readBeat(quint8 header, CMeasure &measure, CStreamTG12::CBeatData &data)
{
    log_debug("Reading beat");
    CBeat beat;

    beat.start(data.currentStart());

    readVoices(header, beat, data);

    if( (header & BEAT_HAS_STROKE) != 0 )
        readStroke(beat.stroke());

    if( (header & BEAT_HAS_CHORD) != 0 )
        beat.chord(readChord());

    if( (header & BEAT_HAS_TEXT) != 0 )
        beat.text(readText());

    measure.beatAdd(beat);
}

void CInputStreamTG12::readVoices(quint8 header, CBeat &beat, CStreamTG12::CBeatData &data)
{
    log_debug("Reading voices");
    for( quint8 i = 0 ; i < CBeat::MAX_VOICES; i++ )
    {
        quint16 shift = i * 2;

        beat.voice(i).empty(true);

        if( (header & (BEAT_HAS_VOICE << shift)) != 0 )
        {
            if( (header & (BEAT_HAS_VOICE_CHANGES << shift)) != 0 )
            {
                log_debug("Reading flags");
                data.voice(i).flags(readUByte());
            }

            qint32 flags = data.voice(i).flags();

            if( (flags & VOICE_NEXT_DURATION) != 0 )
                readDuration(data.voice(i).duration());

            if( (flags & VOICE_HAS_NOTES) != 0 )
                readNotes(beat.voice(i), data);

            if( (flags & VOICE_DIRECTION_UP) != 0 )
                beat.voice(i).direction( CVoice::DIRECTION_UP );
            else if( (flags & VOICE_DIRECTION_DOWN) != 0 )
                beat.voice(i).direction( CVoice::DIRECTION_DOWN );

            data.voice(i).duration(beat.voice(i).duration());
            data.voice(i).start(data.voice(i).start() + beat.voice(i).duration().time());

            beat.voice(i).empty(false);
        }
    }
}

void CInputStreamTG12::readTimeSignature(CTimeSignature &time_signature)
{
    log_debug("Reading numerator");
    time_signature.numerator(readByte());

    log_debug("Reading denominator");
    CDuration duration;
    readDuration(duration);
    time_signature.denominator(duration);
}

void CInputStreamTG12::readDuration(CDuration &duration)
{
    log_debug("Reading duration");
    quint8 header = readUByte();

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

void CInputStreamTG12::readDivisionType(CDivisionType &division)
{
    log_debug("Reading enter");
    division.enter(readByte());

    log_debug("Reading time");
    division.time(readByte());
}

quint8 CInputStreamTG12::readUByte()
{
    quint8 data;
    (*m_data_stream) >> data;
    log_debug("Reading ubyte: %i", data);
    return data;
}

qint32 CInputStreamTG12::readUByte(qint32 count)
{
    qint32 header = 0;
    for(qint32 i = count; i > 0; i--)
        header += ( ((qint32)readUByte() ) << ( (8 * i) - 8 ) );

    return header;
}

qint8 CInputStreamTG12::readByte()
{
    qint8 data;
    (*m_data_stream) >> data;
    log_debug("Reading byte: %i", data);
    return data;
}

qint16 CInputStreamTG12::readShort()
{
    qint16 data;
    (*m_data_stream) >> data;
    log_debug("Reading short: %i", data);
    return data;
}

QString CInputStreamTG12::readUByteString()
{
    quint8 data;
    (*m_data_stream) >> data;
    log_debug("Reading ubyte length: %i", data);

    return data > 0 ? readString(data) : "";
}

QString CInputStreamTG12::readIntegerString()
{
    quint32 data;
    (*m_data_stream) >> data;
    log_debug("Reading integer length: %i, pos: %i", data, m_data_stream->device()->pos());

    return data > 0 ? readString(data) : "";
}

QString CInputStreamTG12::readString(quint64 length)
{
    QTextStream stream(m_data_stream->device());
    quint64 lastpos = m_data_stream->device()->pos();
    stream.setCodec("UTF-16BE");
    QString out = stream.read(length);
    stream.seek(lastpos + length * 2);

    log_debug("Readed string '%1'", out);

    return out;
}

void CInputStreamTG12::readMarker(qint16 measure, CMarker &marker)
{
    marker.measure(measure);

    log_debug("Reading marker title");
    marker.title(readUByteString());

    log_debug("Reading marker color");
    marker.color(readRGBColor());
}

QColor CInputStreamTG12::readRGBColor()
{
    QColor color;
    color.setRed(readUByte());
    color.setGreen(readUByte());
    color.setBlue(readUByte());

    log_debug("Readed color 'R%i G%i B%i'", color.red(), color.green(), color.blue());

    return color;
}

void CInputStreamTG12::readNotes(CVoice &voice, CStreamTG12::CBeatData &data)
{
    log_debug("Reading notes");
    quint8 header = NOTE_HAS_NEXT;
    do
    {
        log_debug("Reading header");
        header = readUByte();
        readNote(header, voice, data);
    }
    while( (header & NOTE_HAS_NEXT) != 0 );
}

void CInputStreamTG12::readNote(quint8 header, CVoice &voice, CStreamTG12::CBeatData &data)
{
    log_debug("Reading note");
    CNote note;

    log_debug("Reading note value");
    note.value(readByte());

    log_debug("Reading note string");
    note.string(readByte());

    log_debug("Reading note tied");
    note.tied((header & NOTE_TIED) != 0);

    log_debug("Reading note velocity");
    if( (header & NOTE_VELOCITY) != 0 )
        data.voice(voice.index()).velocity(readByte());

    note.velocity(data.voice(voice.index()).velocity());

    if( (header & NOTE_EFFECT) != 0 )
        readNoteEffect(note.effect());

    voice.noteAdd(note);
}

void CInputStreamTG12::readNoteEffect(CNoteEffect &effect)
{
    log_debug("Reading note effect");
    qint32 header = readUByte(3);

    if( (header & EFFECT_BEND) != 0 )
        effect.bend(readBendEffect());

    if( (header & EFFECT_TREMOLO_BAR) != 0 )
        effect.tremoloBar(readTremoloBarEffect());

    if( (header & EFFECT_HARMONIC) != 0 )
        effect.harmonic(readHarmonicEffect());

    if( (header & EFFECT_GRACE) != 0 )
        effect.grace(readGraceEffect());

    if( (header & EFFECT_TRILL) != 0 )
        effect.trill(readTrillEffect());

    if( (header & EFFECT_TREMOLO_PICKING) != 0 )
        effect.tremoloPicking(readTremoloPickingEffect());

    // Vibrato
    effect.vibrato((header & EFFECT_VIBRATO) != 0);

    // Dead note
    effect.dead((header & EFFECT_DEAD) != 0);

    // Slide
    effect.slide((header & EFFECT_SLIDE) != 0);

    // Hammer-on/pull-off
    effect.hammer((header & EFFECT_HAMMER) != 0);

    // Ghost note
    effect.ghost((header & EFFECT_GHOST) != 0);

    // Accentuated note
    effect.accentuated((header & EFFECT_ACCENTUATED) != 0);

    // Heavy accentuated note
    effect.heavyAccentuated((header & EFFECT_HEAVY_ACCENTUATED) != 0);

    // Palm mute
    effect.palmMute((header & EFFECT_PALM_MUTE) != 0);

    // Staccato
    effect.staccato((header & EFFECT_STACCATO) != 0);

    // Tapping
    effect.tapping((header & EFFECT_TAPPING) != 0);

    // Slapping
    effect.slapping((header & EFFECT_SLAPPING) != 0);

    // Popping
    effect.popping((header & EFFECT_POPPING) != 0);

    // Fade in
    effect.fadeIn((header & EFFECT_FADE_IN) != 0);

    // Let ring
    effect.letRing((header & EFFECT_LET_RING) != 0);
}

CEffectBend* CInputStreamTG12::readBendEffect()
{
    log_debug("Reading note effect bend");
    CEffectBend *effect = new CEffectBend();

    log_debug("Reading points count");
    qint8 count = readByte();

    for(qint8 i = 0; i < count; i++)
    {
        log_debug("Reading point position");
        qint8 position = readByte();

        log_debug("Reading point value");
        qint8 value = readByte();

        effect->pointAdd(position, value);
    }

    return effect;
}

CEffectTremoloBar* CInputStreamTG12::readTremoloBarEffect()
{
    log_debug("Reading note effect tremolo bar");
    CEffectTremoloBar *effect = new CEffectTremoloBar();

    log_debug("Reading points count");
    qint8 count = readByte();

    for(qint8 i = 0; i < count; i++)
    {
        log_debug("Reading point position");
        qint8 position = readByte();

        log_debug("Reading point value");
        qint8 value = readByte() - CEffectTremoloBar::MAX_VALUE_LENGTH;

        effect->pointAdd(position, value);
    }

    return effect;
}

CEffectHormonic* CInputStreamTG12::readHarmonicEffect()
{
    log_debug("Reading note effect harmonics");
    CEffectHormonic *effect = new CEffectHormonic();

    log_debug("Reading type");
    effect->type(readByte());

    if( effect->type() != CEffectHormonic::TYPE_NATURAL)
    {
        log_debug("Reading data");
        effect->data(readByte());
    }

    return effect;
}

CEffectGrace* CInputStreamTG12::readGraceEffect()
{
    log_debug("Reading note effect grace");
    quint8 header = readUByte();

    CEffectGrace *effect = new CEffectGrace();

    effect->dead((header & GRACE_FLAG_DEAD) != 0) ;

    effect->onBeat((header & GRACE_FLAG_ON_BEAT) != 0) ;

    log_debug("Reading fret");
    effect->fret(readByte());

    log_debug("Reading duration");
    effect->duration(readByte());

    log_debug("Reading dynamic");
    effect->dynamic(readByte());

    log_debug("Reading transition");
    effect->transition(readByte());

    return effect;
}

CEffectTremoloPicking* CInputStreamTG12::readTremoloPickingEffect()
{
    log_debug("Reading note effect trill");
    CEffectTremoloPicking *effect = new CEffectTremoloPicking();

    log_debug("Reading duration value");
    effect->duration().value(readByte());

    return effect;
}

CEffectTrill* CInputStreamTG12::readTrillEffect()
{
    log_debug("Reading note effect tremolo picking");
    CEffectTrill *effect = new CEffectTrill();

    log_debug("Reading fret");
    effect->fret(readByte());

    log_debug("Reading duration value");
    effect->duration().value(readByte());

    return effect;
}

void CInputStreamTG12::readStroke(CStroke &stroke)
{
    log_debug("Reading stroke direction");
    stroke.direction(readByte());

    log_debug("Reading stroke value");
    stroke.value(readByte());
}

CChord* CInputStreamTG12::readChord()
{
    log_debug("Reading chord");
    CChord *chord = new CChord(readByte());

    log_debug("Reading name");
    chord->name(readUByteString());

    log_debug("Reading first fret");
    chord->firstFret(readByte());

    log_debug("Reading frets");
    for( qint8 string = 0; string < chord->stringsCount(); string++ )
        chord->fret(string, readByte());

    return chord;
}

CText* CInputStreamTG12::readText()
{
    log_debug("Reading text");
    CText *text = new CText();

    text->value(readUByteString());

    return text;
}

CString CInputStreamTG12::readInstrumentString(qint8 number)
{
    log_debug("Reading string #%i", number);
    CString string;

    string.number(number);

    log_debug("Reading value");
    string.value(readByte());

    return string;
}

CLyrics CInputStreamTG12::readLyrics()
{
    log_debug("Reading lyrics");
    CLyrics lyrics;

    log_debug("Reading lyrics from");
    lyrics.from(readShort());

    log_debug("Reading lyrics text");
    lyrics.lyrics(readIntegerString());

    return lyrics;
}
