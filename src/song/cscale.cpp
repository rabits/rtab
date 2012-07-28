/**
 * @file    cscale.cpp
 * @date    2012-07-28T01:11:23+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Scale
 *
 */

#include "cscale.h"

CScale::CScale(QObject *parent)
    : QObject(parent)
    , m_key(0)
    , m_notes { false, false, false, false, false, false, false, false, false, false, false, false }
{
}

void CScale::clear()
{
    key(0);
    for(quint8 i = 0; i < 12; i++)
        note(i, false);
}
