/**
 * @file    ceffecttremolopicking.cpp
 * @date    2012-07-28T01:11:23+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Effect - Tremolo Picking
 *
 */

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
