/**
 * @file    cnote.cpp
 * @date    2012-07-28T01:11:23+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Note
 *
 */

#include "cnote.h"

#include "cvelocities.h"

CNote::CNote(QObject *parent)
    : QObject(parent)
    , m_value(0)
    , m_velocity(CVelocities::DEFAULT)
    , m_string(1)
    , m_tied(false)
    , m_effect()
    , p_voice(NULL)
{
}

CNote::CNote(const CNote &obj)
    : QObject()
    , m_value(obj.value())
    , m_velocity(obj.velocity())
    , m_string(obj.string())
    , m_tied(obj.tied())
    , m_effect(obj.effect())
    , p_voice(obj.voice())
{
}

CNote &CNote::operator =(const CNote &obj)
{
    value(obj.value());
    velocity(obj.velocity());
    string(obj.string());
    tied(obj.tied());
    effect(obj.effect());

    return *this;
}
