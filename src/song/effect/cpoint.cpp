#include "cpoint.h"

CPoint::CPoint(quint16 position, qint16 value, QObject *parent)
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
