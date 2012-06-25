#include "cinputstream.h"

#include <QTextStream>
#include <QTextCodec>
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
    m_data_stream->setByteOrder(QDataStream::LittleEndian);
    m_version.clear();
}

bool CInputStream::isSupportedVersion()
{
    try {
        log_debug("Reading version");
        readVersion();
        log_debug("Version readed");
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

CSong* CInputStream::read()
{
    CSong* song = new CSong();

    song->name(readUnsignedByteString());
    song->artist(readUnsignedByteString());
    song->album(readUnsignedByteString());
    song->author(readUnsignedByteString());
    song->date(readUnsignedByteString());
    song->copyright(readUnsignedByteString());
    song->writer(readUnsignedByteString());
    song->transcriber(readUnsignedByteString());
    song->comments(readUnsignedByteString());

    qint8 channel_count = readByte();
}

qint8 CInputStream::readByte()
{
    qint16 data;
    (*m_data_stream) >> data;
    return (qint8)data;
}

QString CInputStream::readUnsignedByteString()
{
    quint16 data;
    (*m_data_stream) >> data;
    return readString( data & 0xFF );
}

QString CInputStream::readString(quint64 length)
{
    log_debug("Reading string length: %i", length);

    QTextStream stream(m_data_stream->device());
    stream.setCodec(QTextCodec::codecForName("utf16"));
    QString out = stream.read(length);

    log_debug("Finished reading %1", out);

    return out;
}
