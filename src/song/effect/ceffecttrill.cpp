#include "ceffecttrill.h"

CEffectTrill::CEffectTrill(QObject *parent)
    : QObject(parent)
    , m_fret(0)
    , m_duration()
{
}

CEffectTrill::CEffectTrill(const CEffectTrill &obj)
    : QObject()
    , m_fret(obj.fret())
    , m_duration(obj.duration())
{
}

CEffectTrill &CEffectTrill::operator =(const CEffectTrill &obj)
{
    fret(obj.fret());
    duration(obj.duration());

    return *this;
}
