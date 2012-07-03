#ifndef CSONG_H
#define CSONG_H

#include "src/common/common.h"

#include <QObject>

#include "ctrack.h"
#include "cmeasureheader.h"
#include "cchannel.h"

class CSong
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString               name READ name WRITE name NOTIFY nameChanged)
    Q_PROPERTY(QString               artist READ artist WRITE artist NOTIFY artistChanged)
    Q_PROPERTY(QString               album READ album WRITE album NOTIFY albumChanged)
    Q_PROPERTY(QString               author READ author WRITE author NOTIFY authorChanged)
    Q_PROPERTY(QString               date READ date WRITE date NOTIFY dateChanged)
    Q_PROPERTY(QString               copyright READ copyright WRITE copyright NOTIFY copyrightChanged)
    Q_PROPERTY(QString               writer READ writer WRITE writer NOTIFY writerChanged)
    Q_PROPERTY(QString               transcriber READ transcriber WRITE transcriber NOTIFY transcriberChanged)
    Q_PROPERTY(QString               comments READ comments WRITE comments NOTIFY commentsChanged)
    Q_PROPERTY(QList<CTrack>         tracks READ tracks WRITE tracks NOTIFY tracksChanged)
    Q_PROPERTY(QList<CMeasureHeader> measureHeaders READ measureHeaders WRITE measureHeaders NOTIFY measureHeadersChanged)
    Q_PROPERTY(QList<CChannel>       channels READ channels WRITE channels NOTIFY channelsChanged)

public:
    explicit CSong(QObject *parent = 0);
    CSong(const CSong &obj);
    CSong& operator=(const CSong &obj);

    // --API--- //
    inline const QString&               name()           const { return m_name; }
    inline const QString&               artist()         const { return m_artist; }
    inline const QString&               album()          const { return m_album; }
    inline const QString&               author()         const { return m_author; }
    inline const QString&               date()           const { return m_date; }
    inline const QString&               copyright()      const { return m_copyright; }
    inline const QString&               writer()         const { return m_writer; }
    inline const QString&               transcriber()    const { return m_transcriber; }
    inline const QString&               comments()       const { return m_comments; }
    inline const QList<CTrack>&         tracks()         const { return m_tracks; }
    inline const QList<CMeasureHeader>& measureHeaders() const { return m_measureHeaders; }
    inline const QList<CChannel>&       channels()       const { return m_channels; }

    inline void name(const QString &val)                         { m_name = val; emit nameChanged(); }
    inline void artist(const QString &val)                       { m_artist = val; emit artistChanged(); }
    inline void album(const QString &val)                        { m_album = val; emit albumChanged(); }
    inline void author(const QString &val)                       { m_author = val; emit authorChanged(); }
    inline void date(const QString &val)                         { m_date = val; emit dateChanged(); }
    inline void copyright(const QString &val)                    { m_copyright = val; emit copyrightChanged(); }
    inline void writer(const QString &val)                       { m_writer = val; emit writerChanged(); }
    inline void transcriber(const QString &val)                  { m_transcriber = val; emit transcriberChanged(); }
    inline void comments(const QString &val)                     { m_comments = val; emit commentsChanged(); }
    inline void tracks(const QList<CTrack> &val)                 { m_tracks = val; emit tracksChanged(); }
    inline void measureHeaders(const QList<CMeasureHeader> &val) { m_measureHeaders = val; emit measureHeadersChanged(); }
    inline void channels(const QList<CChannel> &val)             { m_channels = val; emit channelsChanged(); }


    inline quint8        tracksCount()                          const { return m_tracks.count(); }
    inline const CTrack& track(const quint8 index)              const { return m_tracks[index]; }
    inline CTrack&       track(const quint8 index)                    { return m_tracks[index]; }
    inline void          track(const quint8 index, const CTrack &val) { m_tracks[index] = val; m_tracks[index].song(this); emit tracksChanged(); }
    inline void          trackAdd(const CTrack &val)                  { m_tracks.append(val); m_tracks.last().song(this); emit tracksChanged(); }
    inline void          trackRemove(const quint8 index)              { m_tracks.removeAt(index); emit tracksChanged(); }
    inline void          trackRemove(const CTrack &val)               { m_tracks.removeOne(val); emit tracksChanged(); }

    inline quint16               measureHeadersCount()                                   const { return m_measureHeaders.count(); }
    inline const CMeasureHeader& measureHeader(const quint16 index)                      const { return m_measureHeaders[index]; }
    inline CMeasureHeader&       measureHeader(const quint16 index)                            { return m_measureHeaders[index]; }
    inline void                  measureHeader(const quint16 index, const CMeasureHeader &val) { m_measureHeaders[index] = val; m_measureHeaders[index].song(this); emit measureHeadersChanged(); }
    inline void                  measureHeaderAdd(const CMeasureHeader &val)                   { m_measureHeaders.append(val); m_measureHeaders.last().song(this); emit measureHeadersChanged(); }
    inline void                  measureHeaderRemove(const quint16 index)                      { m_measureHeaders.removeAt(index); emit measureHeadersChanged(); }
    inline void                  measureHeaderRemove(const CMeasureHeader &val)                { m_measureHeaders.removeOne(val); emit measureHeadersChanged(); }

    inline quint8          channelsCount()                            const { return m_channels.count(); }
    inline const CChannel& channel(const quint8 index)                const { return m_channels[index]; }
    inline CChannel&       channel(const quint8 index)                      { return m_channels[index]; }
    inline void            channel(const quint8 index, const CChannel &val) { m_channels[index] = val; emit channelsChanged(); }
    inline void            channelAdd(const CChannel &val)                  { m_channels.append(val); emit channelsChanged(); }
    inline void            channelRemove(const quint8 index)                { m_channels.removeAt(index); emit channelsChanged(); }
    inline void            channelRemove(const CChannel &val)               { m_channels.removeOne(val); emit channelsChanged(); }

    inline bool isEmpty() const { return measureHeadersCount() == 0 || tracksCount() == 0; }
    void              clear()         { m_channels.clear(); m_measureHeaders.clear(); m_tracks.clear(); }

signals:
    void nameChanged();
    void artistChanged();
    void albumChanged();
    void authorChanged();
    void dateChanged();
    void copyrightChanged();
    void writerChanged();
    void transcriberChanged();
    void commentsChanged();
    void tracksChanged();
    void measureHeadersChanged();
    void channelsChanged();

protected:
    QString               m_name;
    QString               m_artist;
    QString               m_album;
    QString               m_author;
    QString               m_date;
    QString               m_copyright;
    QString               m_writer;
    QString               m_transcriber;
    QString               m_comments;
    QList<CTrack>         m_tracks;
    QList<CMeasureHeader> m_measureHeaders;
    QList<CChannel>       m_channels;
};

#endif // CSONG_H
