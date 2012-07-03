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
    inline void readVersion();
    CSong*      read();

    void readChannel(CChannel &channel);
    void readChannelParameters(CChannel &channel);
    void readChannelParameter(CChannel &channel);
    CMeasureHeader readMeasureHeader(CMeasureHeader &measure_header, qint32 number, qint64 start, const CMeasureHeader *last_header);
    void readTempo(CTempo &tempo);
    void readMarker(qint32 number, CMarker &marker);
    qint32 readHeader();
    void readTimeSignature(CTimeSignature &time_signature);
    void readDuration(CDuration &duration);
    void readDivisionType(CDivisionType &division);
    qint32 readHeader(qint32 count);
    void readTrack(qint8 number, CSong *song, CTrack &track);
    CMeasure readMeasure(CMeasureHeader &measure_header, CMeasure *last_measure);
    void readBeats(CMeasure &measure, CBeatData &data);
    void readBeat(quint32 header, CMeasure &measure, CBeatData &data);
    void readVoices(quint32 header, CBeat &beat, CBeatData &data);

    qint8   readByte();
    qint16  readShort();

    QString readUnsignedByteString();
    QString readIntegerString();
    QString readString(quint64 length);

    QDataStream *m_data_stream;
    QString      m_version;
};

#endif // CINPUTSTREAM_H
