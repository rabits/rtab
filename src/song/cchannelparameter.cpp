#include "cchannelparameter.h"

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
