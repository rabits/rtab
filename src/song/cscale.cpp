#include "cscale.h"

CScale::CScale(QObject *parent)
    : QObject(parent)
    , m_key(0)
    , m_notes({false, false, false, false, false, false, false, false, false, false, false, false})
{
}

void CScale::clear()
{
    key(0);
    for(int i = 0; i < 12; i++)
        note(i, false);
}
