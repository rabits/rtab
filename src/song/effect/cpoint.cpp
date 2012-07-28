/**
 * @file    cpoint.cpp
 * @date    2012-07-28T01:11:23+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Point for some effects
 *
 */

#include "cpoint.h"

CPoint::CPoint(qint8 position, qint8 value, QObject *parent)
    : QObject(parent)
    , m_position(position)
    , m_value(value)
{
}

CPoint::CPoint(const CPoint &obj)
    : QObject()
    , m_position(obj.position())
    , m_value(obj.value())
{
}

CPoint &CPoint::operator =(const CPoint &obj)
{
    position(obj.position());
    value(obj.value());

    return *this;
}
