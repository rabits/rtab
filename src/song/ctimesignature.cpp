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
