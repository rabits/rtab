#ifndef CCHORD_H
#define CCHORD_H

#include "src/common/common.h"

#include <QObject>

class CBeat;

class CChord
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qint8        firstFret READ firstFret WRITE firstFret NOTIFY firstFretChanged)
    Q_PROPERTY(QList<qint8> strings READ strings WRITE strings NOTIFY stringsChanged)
    Q_PROPERTY(QString      name READ name WRITE name NOTIFY nameChanged)
    Q_PROPERTY(CBeat*       beat READ beat WRITE beat NOTIFY beatChanged)

public:
    explicit CChord(qint8 length, QObject *parent = 0);
    CChord(const CChord &obj);
    CChord& operator=(const CChord &obj);

    // ---API--- //
    inline qint8               firstFret() const { return m_firstFret; }
    inline const QList<qint8>& strings()   const { return m_strings; }
    inline const QString&      name()      const { return m_name; }
    inline CBeat*              beat()      const { return p_beat; }

    inline void firstFret(const qint8 val)       { m_firstFret = val; emit firstFretChanged(); }
    inline void strings(const QList<qint8> &val) { m_strings = val; emit stringsChanged(); }
    inline void name(const QString &val)         { m_name = val; emit nameChanged(); }
    inline void beat(CBeat *val)                 { p_beat = val; emit beatChanged(); }

    inline quint8 stringsCount() const { return m_strings.count(); }

    inline qint8  fret(const quint8 string) const;
    inline void   fret(const quint8 string, const qint8 val);

    quint8        notesCount() const;

signals:
    void firstFretChanged();
    void stringsChanged();
    void nameChanged();
    void beatChanged();

private:
    qint8        m_firstFret;
    QList<qint8> m_strings;
    QString      m_name;
    CBeat       *p_beat;
};

#endif // CCHORD_H
