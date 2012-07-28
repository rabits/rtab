/**
 * @file    ceffecttrill.cpp
 * @date    2012-07-28T01:11:23+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Effect - Trill
 *
 */

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
