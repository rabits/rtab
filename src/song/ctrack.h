#ifndef CTRACK_H
#define CTRACK_H

#include "src/common/common.h"

#include <QObject>
#include <QColor>

#include "cmeasure.h"
#include "cstring.h"
#include "clyrics.h"

class CSong;

class CTrack
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(quint16         number READ number WRITE number NOTIFY numberChanged)
    Q_PROPERTY(qint16          offset READ offset WRITE offset NOTIFY offsetChanged)
    Q_PROPERTY(qint16          channelId READ channelId WRITE channelId NOTIFY channelIdChanged)
    Q_PROPERTY(bool            solo READ solo WRITE solo NOTIFY soloChanged)
    Q_PROPERTY(bool            mute READ mute WRITE mute NOTIFY muteChanged)
    Q_PROPERTY(QString         name READ name WRITE name NOTIFY nameChanged)
    Q_PROPERTY(QList<CMeasure> measures READ measures WRITE measures NOTIFY measuresChanged)
    Q_PROPERTY(QList<CString>  strings READ strings WRITE strings NOTIFY stringsChanged)
    Q_PROPERTY(QColor          color READ color WRITE color NOTIFY colorChanged)
    Q_PROPERTY(CLyrics          lyrics READ lyrics WRITE lyrics NOTIFY lyricsChanged)
    Q_PROPERTY(CSong*          song READ song WRITE song NOTIFY songChanged)

public:
    explicit CTrack(QObject *parent = 0);
    CTrack(const CTrack &obj);
    CTrack& operator=(const CTrack &obj);

    inline bool operator==(const CTrack &obj) const { return offset() == obj.offset() && channelId() == obj.channelId()
                                                                && solo() == obj.solo() && mute() == obj.mute()
                                                                && name() == obj.name() && measures() == obj.measures()
                                                                && color() == obj.color() && lyrics() == obj.lyrics() ; }

    static const qint16 MAX_OFFSET = 24;
    static const qint16 MIN_OFFSET = -24;

    // ---API--- //
    inline quint16                number()    const { return m_number; }
    inline qint16                 offset()    const { return m_offset; }
    inline qint16                 channelId() const { return m_channelId; }
    inline bool                   solo()      const { return m_solo; }
    inline bool                   mute()      const { return m_mute; }
    inline const QString&         name()      const { return m_name; }
    inline const QList<CMeasure>& measures()  const { return m_measures; }
    inline const QList<CString>&  strings()   const { return m_strings; }
    inline const QColor&          color()     const { return m_color; }
    inline const CLyrics&         lyrics()    const { return m_lyrics; }
    inline CLyrics&               lyrics()          { return m_lyrics; }
    inline CSong*                 song()      const { return p_song; }

    inline void number(const quint16 &val)           { m_number = val; emit numberChanged(); }
    inline void offset(const qint16 &val)            { m_offset = val; emit offsetChanged(); }
    inline void channelId(const qint16 &val)         { m_channelId = val; emit channelIdChanged(); }
    inline void solo(const bool &val)                { m_solo = val; emit soloChanged(); }
    inline void mute(const bool &val)                { m_mute = val; emit muteChanged(); }
    inline void name(const QString &val)             { m_name = val; emit nameChanged(); }
    inline void measures(const QList<CMeasure> &val) { m_measures = val; emit measuresChanged(); }
    inline void strings(const QList<CString> &val)   { m_strings = val; emit stringsChanged(); }
    inline void color(const QColor &val)             { m_color = val; emit colorChanged(); }
    inline void lyrics(const CLyrics &val)           { m_lyrics = val; emit lyricsChanged(); }
    inline void song(CSong *val)                     { p_song = val; updateSongLinks(); emit songChanged(); }


    inline quint16         measuresCount()                             const { return m_measures.count(); }
    inline const CMeasure& measure(const quint16 index)                const { return m_measures[index]; }
    inline CMeasure&       measure(const quint16 index)                      { return m_measures[index]; }
    inline void            measure(const quint16 index, const CMeasure &val) { m_measures[index] = val; m_measures[index].track(this); emit measuresChanged(); }
    inline void            measureAdd(const CMeasure &val)                   { m_measures.append(val); m_measures.last().track(this); emit measuresChanged(); }
    inline void            measureRemove(const quint16 index)                { m_measures.removeAt(index); emit measuresChanged(); }
    inline void            measureRemove(const CMeasure &val)                { m_measures.removeOne(val); emit measuresChanged(); }

    inline quint8         stringsCount()                           const { return m_strings.count(); }
    inline const CString& string(const quint8 index)               const { return m_strings[index-1]; }
    inline CString&       string(const quint8 index)                     { return m_strings[index-1]; }
    inline void           string(const quint8 index, const CString &val) { m_strings[index-1] = val; emit stringsChanged(); }
    inline void           stringAdd(const CString &val)                  { m_strings.append(val); emit stringsChanged(); }
    inline void           stringRemove(const quint8 index)               { m_strings.removeAt(index); emit stringsChanged(); }
    inline void           stringRemove(const CString &val)               { m_strings.removeOne(val); emit stringsChanged(); }

    inline void clear() { m_strings.clear(); m_measures.clear(); }

signals:
    void numberChanged();
    void offsetChanged();
    void channelIdChanged();
    void soloChanged();
    void muteChanged();
    void nameChanged();
    void measuresChanged();
    void stringsChanged();
    void colorChanged();
    void lyricsChanged();
    void songChanged();

private:
    void updateSongLinks();

    quint16         m_number;
    qint16          m_offset;
    qint16          m_channelId;
    bool            m_solo;
    bool            m_mute;
    QString         m_name;
    QList<CMeasure> m_measures;
    QList<CString>  m_strings;
    QColor          m_color;
    CLyrics         m_lyrics;
    CSong          *p_song;
};

#endif // CTRACK_H
