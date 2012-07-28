/**
 * @file    ceffecthormonic.cpp
 * @date    2012-07-28T01:11:23+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Effect - Hormonic
 *
 */

#include "ceffecthormonic.h"

const char* CEffectHormonic::KEY_NATURAL    = "N.H";
const char* CEffectHormonic::KEY_ARTIFICIAL = "A.H";
const char* CEffectHormonic::KEY_TAPPED     = "T.H";
const char* CEffectHormonic::KEY_PINCH      = "P.H";
const char* CEffectHormonic::KEY_SEMI       = "S.H";

CEffectHormonic::CEffectHormonic(QObject *parent)
    : QObject(parent)
    , m_type(TYPE_NONE)
    , m_data(0)
{
}

CEffectHormonic::CEffectHormonic(const CEffectHormonic &obj)
    : QObject()
    , m_type(obj.type())
    , m_data(obj.data())
{
}

CEffectHormonic &CEffectHormonic::operator =(const CEffectHormonic &obj)
{
    type(obj.type());
    data(obj.data());

    return *this;
}
