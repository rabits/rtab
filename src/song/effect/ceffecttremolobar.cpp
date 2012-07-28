/**
 * @file    ceffecttremolobar.cpp
 * @date    2012-07-28T01:11:23+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Effect - Tremolo Bar
 *
 */

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

CEffectTremoloBar::CPointTremoloBar::CPointTremoloBar(quint16 position, qint16 value, QObject *parent)
    : CPoint(position, value, parent)
{
}
