/**
 * @file    ceffectbend.cpp
 * @date    2012-07-28T01:11:23+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Effect - Bend
 *
 */

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

CEffectBend::CPointBend::CPointBend(qint8 position, qint8 value, QObject *parent)
    : CPoint(position, value, parent)
{
}
