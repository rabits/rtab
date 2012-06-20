#include "ceffecttremolopicking.h"

CEffectTremoloPicking::CEffectTremoloPicking(QObject *parent)
    : QObject(parent)
    , m_duration()
{
}

CEffectTremoloPicking::CEffectTremoloPicking(const CEffectTremoloPicking &obj)
    : QObject()
    , m_duration(obj.duration())
{
}

CEffectTremoloPicking &CEffectTremoloPicking::operator =(const CEffectTremoloPicking &obj)
{
    duration(obj.duration());

    return *this;
}
