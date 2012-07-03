#ifndef CEFFECTTRILL_H
#define CEFFECTTRILL_H

#include <QObject>

#include "../cduration.h"

class CEffectTrill
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(quint16   fret READ fret WRITE fret NOTIFY fretChanged)
    Q_PROPERTY(CDuration duration READ duration WRITE duration NOTIFY durationChanged)

public:
    explicit CEffectTrill(QObject *parent = 0);
    CEffectTrill(const CEffectTrill &obj);
    CEffectTrill& operator=(const CEffectTrill &obj);

    // ---API--- //
    inline quint16          fret()     const { return m_fret; }
    inline const CDuration& duration() const { return m_duration; }
    inline CDuration&       duration()       { return m_duration; }

    inline void fret(const quint16 val)        { m_fret = val; emit fretChanged(); }
    inline void duration(const CDuration &val) { m_duration = val; emit durationChanged(); }

signals:
    void fretChanged();
    void durationChanged();

private:
    quint16   m_fret;
    CDuration m_duration;
};

#endif // CEFFECTTRILL_H
