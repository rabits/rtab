/**
 * @file    cchannelparameter.cpp
 * @date    2012-07-28T01:11:23+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Channel Parameter
 *
 */

#include "cchannelparameter.h"

CChannelParameter::CChannelParameter(QString key, QString value, QObject *parent)
    : QObject(parent)
    , m_key(key)
    , m_value(value)
{
}

CChannelParameter::CChannelParameter(QObject *parent)
    : QObject(parent)
    , m_key()
    , m_value()
{
}

CChannelParameter::CChannelParameter(const CChannelParameter &obj)
    : QObject()
    , m_key(obj.key())
    , m_value(obj.value())
{
}

CChannelParameter &CChannelParameter::operator =(const CChannelParameter &obj)
{
    key(obj.key());
    value(obj.value());

    return *this;
}
