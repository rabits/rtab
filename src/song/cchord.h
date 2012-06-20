#ifndef CCHORD_H
#define CCHORD_H

#include "src/common/common.h"

#include <QObject>

class CBeat;

class CChord
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int        firstFret READ firstFret WRITE firstFret NOTIFY firstFretChanged)
    Q_PROPERTY(QList<int> strings READ strings WRITE strings NOTIFY stringsChanged)
    Q_PROPERTY(QString    name READ name WRITE name NOTIFY nameChanged)
    Q_PROPERTY(CBeat*     beat READ beat WRITE beat NOTIFY beatChanged)

public:
    explicit CChord(int length, QObject *parent = 0);
    CChord(const CChord &obj);
    CChord& operator=(const CChord &obj);

    // ---API--- //
    inline int               firstFret() const { return m_firstFret; }
    inline const QList<int>& strings()   const { return m_strings; }
    inline const QString&    name()      const { return m_name; }
    inline CBeat*            beat()      const { return p_beat; }

    inline void firstFret(const int val)       { m_firstFret = val; emit firstFretChanged(); }
    inline void strings(const QList<int> &val) { m_strings = val; emit stringsChanged(); }
    inline void name(const QString &val)       { m_name = val; emit nameChanged(); }
    inline void beat(CBeat *val)               { p_beat = val; emit beatChanged(); }

    inline uint stringsCount() const { return m_strings.count(); }

    inline int  fret(const uint string) const;
    inline void fret(const uint string, const int val);

    uint        notesCount() const;

signals:
    void firstFretChanged();
    void stringsChanged();
    void nameChanged();
    void beatChanged();

private:
    int        m_firstFret;
    QList<int> m_strings;
    QString    m_name;
    CBeat      *p_beat;
};

#endif // CCHORD_H
