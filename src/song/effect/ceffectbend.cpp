#include "ceffectbend.h"

CEffectBend::CEffectBend(QObject *parent)
    : QObject(parent)
    , m_points()
{
}

CEffectBend::CEffectBend(const CEffectBend &obj)
    : QObject()
    , m_points(obj.points())
{
}

CEffectBend &CEffectBend::operator =(const CEffectBend &obj)
{
    m_points.clear();
    points(obj.points());

    return *this;
}

CEffectBend::CPointBend::CPointBend(int position, int value, QObject *parent)
    : CPoint(position, value, parent)
{
}
