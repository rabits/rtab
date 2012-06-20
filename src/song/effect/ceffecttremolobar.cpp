#include "ceffecttremolobar.h"

CEffectTremoloBar::CEffectTremoloBar(QObject *parent)
    : QObject(parent)
    , m_points()
{
}

CEffectTremoloBar::CEffectTremoloBar(const CEffectTremoloBar &obj)
    : QObject()
    , m_points(obj.points())
{
}

CEffectTremoloBar &CEffectTremoloBar::operator =(const CEffectTremoloBar &obj)
{
    m_points.clear();
    points(obj.points());

    return *this;
}

CEffectTremoloBar::CPointTremoloBar::CPointTremoloBar(int position, int value, QObject *parent)
    : CPoint(position, value, parent)
{
}
