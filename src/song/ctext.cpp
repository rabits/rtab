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
