/**
 * @file    inputstream.h
 * @date    2012-07-27T17:58:18+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Input Stream for tg 1.2-current_svn
 *
 */

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
    void   readVersion();
    CSong* read();

    void readChannel(CChannel &channel);
    void readChannelParameters(CChannel &channel);
    void readChannelParameter(CChannel &channel);
    void readMeasureHeader(CMeasureHeader &measure_header, qint32 number, qint64 start, const CMeasureHeader *last_header);
    void readTempo(CTempo &tempo);
    void readMarker(qint16 measure, CMarker &marker);
    QColor readRGBColor();
    void readTimeSignature(CTimeSignature &time_signature);
    void readDuration(CDuration &duration);
    void readDivisionType(CDivisionType &division);
    void readTrack(qint8 number, CSong *song, CTrack &track);
    CMeasure readMeasure(CMeasureHeader &measure_header, CMeasure *last_measure);
    void readBeats(CMeasure &measure, CBeatData &data);
    void readBeat(quint8 header, CMeasure &measure, CBeatData &data);
    void readVoices(quint8 header, CBeat &beat, CBeatData &data);
    void readNotes(CVoice &voice, CBeatData &data);
    void readNote(quint8 header, CVoice &voice, CBeatData &data);
    void readNoteEffect(CNoteEffect &effect);
    CEffectBend*           readBendEffect();
    CEffectTremoloBar*     readTremoloBarEffect();
    CEffectHormonic*       readHarmonicEffect();
    CEffectGrace*          readGraceEffect();
    CEffectTrill*          readTrillEffect();
    CEffectTremoloPicking* readTremoloPickingEffect();
    void readStroke(CStroke &stroke);
    CChord* readChord();
    CText*  readText();
    CString readInstrumentString(qint8 number);
    CLyrics readLyrics();

    quint8  readUByte();
    qint32  readUByte(qint32 count);
    qint8   readByte();
    qint16  readShort();

    QString readUByteString();
    QString readIntegerString();
    QString readString(quint64 length);

    QDataStream *m_data_stream;
    QString      m_version;
};

#endif // CINPUTSTREAM_H
