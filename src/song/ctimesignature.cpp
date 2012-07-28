/**
 * @file    ctimesignature.cpp
 * @date    2012-07-28T01:11:23+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Time Signature
 *
 */

#include "ctimesignature.h"

CTimeSignature::CTimeSignature(QObject *parent)
    : QObject(parent)
    , m_denominator()
    , m_numerator(4)
{
}

CTimeSignature::CTimeSignature(const CTimeSignature &obj)
    : QObject()
    , m_denominator(obj.denominator())
    , m_numerator(obj.numerator())
{
}

CTimeSignature &CTimeSignature::operator =(const CTimeSignature &obj)
{
    denominator(obj.denominator());
    numerator(obj.numerator());

    return *this;
}
