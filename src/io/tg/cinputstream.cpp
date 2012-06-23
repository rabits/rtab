#include "cinputstream.h"

#include <QTextStream>
#include <QTextCodec>
#include <QDebug>

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
    log_notice("Is supported?");
    try {
        readVersion();
        log_notice("Version readed");
        return isSupportedVersion(m_version);
    }
    catch( ... ) {
        return false;
    }
}

CSong CInputStream::readSong()
{
    log_notice("Song reading");
    // TODO
}

QString CInputStream::readUnsignedByteString()
{
    quint16 data;
    (*m_data_stream) >> data;
    return readString( data & 0xFF );
}

QString CInputStream::readString(int length)
{
    log_notice("Reading string length: %i", length);

    QTextStream stream(m_data_stream->device());
    stream.setCodec(QTextCodec::codecForName("utf16"));
    QString out = stream.read(length);

    log_notice("Finished reading %s", out.toStdString().c_str());

    return out;
}
