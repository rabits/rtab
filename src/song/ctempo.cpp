/**
 * @file    ctempo.cpp
 * @date    2012-07-28T01:11:23+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Tempo
 *
 */

#include "ctempo.h"

CTempo::CTempo(qint16 value, QObject *parent)
    : QObject(parent)
    , m_value(value)
{
}

CTempo::CTempo(const CTempo &obj)
    : QObject()
    , m_value(obj.value())
{
}

CTempo &CTempo::operator =(const CTempo &obj)
{
    value(obj.value());

    return *this;
}
