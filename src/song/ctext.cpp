/**
 * @file    ctext.cpp
 * @date    2012-07-28T01:11:23+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Text
 *
 */

#include "ctext.h"

CText::CText(QObject *parent)
    : QObject(parent)
    , m_value()
    , p_beat(NULL)
{
}

CText::CText(const CText &obj)
    : QObject()
    , m_value(obj.value())
    , p_beat(obj.beat())
{
}

CText &CText::operator =(const CText &obj)
{
    value(obj.value());

    return *this;
}
