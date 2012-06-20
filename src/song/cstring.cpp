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
