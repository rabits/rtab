#include "ceffectgrace.h"

#include "../cvelocities.h"

CEffectGrace::CEffectGrace(QObject *parent)
    : QObject(parent)
    , m_fret(0)
    , m_duration(1)
    , m_dynamic(CVelocities::DEFAULT)
    , m_transition(TRANSITION_NONE)
    , m_onBeat(false)
    , m_dead(false)
{
}

CEffectGrace::CEffectGrace(const CEffectGrace &obj)
    : QObject()
    , m_fret(obj.fret())
    , m_duration(obj.duration())
    , m_dynamic(obj.dynamic())
    , m_transition(obj.transition())
    , m_onBeat(obj.onBeat())
    , m_dead(obj.dead())
{
}

CEffectGrace &CEffectGrace::operator =(const CEffectGrace &obj)
{
    fret(obj.fret());
    duration(obj.duration());
    dynamic(obj.dynamic());
    transition(obj.transition());
    onBeat(obj.onBeat());
    dead(obj.dead());

    return *this;
}
