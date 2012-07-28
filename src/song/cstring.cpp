/**
 * @file    cstring.cpp
 * @date    2012-07-28T01:11:23+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   String
 *
 */

#include "cstring.h"

CString::CString(QObject *parent)
    : QObject(parent)
    , m_number(0)
    , m_value(0)
{
}

CString::CString(const CString &obj)
    : QObject()
    , m_number(obj.number())
    , m_value(obj.value())
{
}

CString &CString::operator =(const CString &obj)
{
    number(obj.number());
    value(obj.value());

    return *this;
}
