#include "ctempo.h"

CTempo::CTempo(int value, QObject *parent)
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
