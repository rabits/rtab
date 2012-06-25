#ifndef CEFFECTGRACE_H
#define CEFFECTGRACE_H

#include <QObject>

#include "../cduration.h"

class CEffectGrace
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(quint16 fret READ fret WRITE fret NOTIFY fretChanged)
    Q_PROPERTY(quint16 duration READ duration WRITE duration NOTIFY durationChanged)
    Q_PROPERTY(qint16  dynamic READ dynamic WRITE dynamic NOTIFY dynamicChanged)
    Q_PROPERTY(qint16  transition READ transition WRITE transition NOTIFY transitionChanged)
    Q_PROPERTY(bool    onBeat READ onBeat WRITE onBeat NOTIFY onBeatChanged)
    Q_PROPERTY(bool    dead READ dead WRITE dead NOTIFY deadChanged)

public:
    explicit CEffectGrace(QObject *parent = 0);
    CEffectGrace(const CEffectGrace &obj);
    CEffectGrace& operator=(const CEffectGrace &obj);

    enum TRANSITION {
        TRANSITION_NONE   = 0,
        TRANSITION_SLIDE  = 1,
        TRANSITION_BEND   = 2,
        TRANSITION_HAMMER = 3
    };

    // ---API--- //
    inline quint16 fret()       const { return m_fret; }
    inline quint16 duration()   const { return m_duration; }
    inline qint16  dynamic()    const { return m_dynamic; }
    inline qint16  transition() const { return m_transition; }
    inline bool    onBeat()     const { return m_onBeat; }
    inline bool    dead()       const { return m_dead; }

    inline void fret(const quint16 val)      { m_fret = val; emit fretChanged(); }
    inline void duration(const quint16 val)  { m_duration = val; emit durationChanged(); }
    inline void dynamic(const qint16 val)    { m_dynamic = val; emit dynamicChanged(); }
    inline void transition(const qint16 val) { m_transition = val; emit transitionChanged(); }
    inline void onBeat(const bool val)       { m_onBeat = val; emit onBeatChanged(); }
    inline void dead(const bool val)         { m_dead = val; emit deadChanged(); }

    inline qint64 durationTime() { return (CDuration::QUARTER_TIME / 16.0f ) * duration(); }

signals:
    void fretChanged();
    void durationChanged();
    void dynamicChanged();
    void transitionChanged();
    void onBeatChanged();
    void deadChanged();

private:
    quint16 m_fret;
    quint16 m_duration;
    qint16  m_dynamic;
    qint16  m_transition;
    bool    m_onBeat;
    bool    m_dead;
};

#endif // CEFFECTGRACE_H
