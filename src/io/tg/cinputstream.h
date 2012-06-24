#ifndef CINPUTSTREAM_H
#define CINPUTSTREAM_H

#include "cstream.h"
#include "../base/cinputstreambase.h"

class CInputStream
    : public CStream
    , public CInputStreamBase
{
public:
    CInputStream();
    ~CInputStream();

    void init(QDataStream *stream);
    bool isSupportedVersion();
    bool isSupportedVersion(QString &version) { log_debug(version == tgVersion() ? "Version match ('%1' == '%2')" : "Version not match ('%1' != '%2')", version, tgVersion() ); return version == tgVersion(); }

    inline CFileFormat getFileFormat() { return CFileFormat("TuxGuitar", QStringList(tgExtension())); }
    CSong*             readSong();

private:
    inline void readVersion() { if( m_version.isEmpty() ) m_version = readUnsignedByteString(); }

    QString readUnsignedByteString();
    QString readString(int length);

    QDataStream *m_data_stream;
    QString      m_version;
};

#endif // CINPUTSTREAM_H
