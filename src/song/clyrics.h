#ifndef CLYRIC_H
#define CLYRIC_H

#include "src/common/common.h"

#include <QObject>
#include <QStringList>

class CLyrics
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int     from READ from WRITE from NOTIFY fromChanged)
    Q_PROPERTY(QString lyrics READ lyrics WRITE lyrics NOTIFY lyricsChanged)

public:
    explicit CLyrics(QObject *parent = 0);
    CLyrics(const CLyrics &obj);
    CLyrics& operator=(const CLyrics &obj);

    inline bool operator==(const CLyrics &obj) const { return from() == obj.from() && lyrics() == obj.lyrics(); }

    //static const char* REPLACE = " ";

    // ---API--- //
    inline int            from()   const { return m_from; }
    inline const QString& lyrics() const { return m_lyrics; }

    inline void from(const int val)        { m_from = val; emit fromChanged(); }
    inline void lyrics(const QString &val) { m_lyrics = val; emit lyricsChanged(); }

    QStringList getLyricsBeats() const;
    inline bool isEmpty() const { return lyrics().isEmpty(); }

signals:
    void fromChanged();
    void lyricsChanged();

private:
    int     m_from;
    QString m_lyrics;
};

#endif // CLYRIC_H
