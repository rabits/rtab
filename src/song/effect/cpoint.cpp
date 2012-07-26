#include "cpoint.h"

CPoint::CPoint(qint8 position, qint8 value, QObject *parent)
    : QObject(parent)
    , m_position(position)
    , m_value(value)
{
}

CPoint::CPoint(const CPoint &obj)
    : QObject()
    , m_position(obj.position())
    , m_value(obj.value())
{
}

CPoint &CPoint::operator =(const CPoint &obj)
{
    position(obj.position());
    value(obj.value());

    return *this;
}
