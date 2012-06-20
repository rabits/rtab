#include "cdivisiontype.h"

const CDivisionType CDivisionType::NORMAL = CDivisionType(1,1);
const CDivisionType CDivisionType::TRIPLET = CDivisionType(3,2);

CDivisionType::CDivisionType(QObject *parent)
    : QObject(parent)
    , m_enter(1)
    , m_time(1)
{
}

CDivisionType::CDivisionType(int enter, int time, QObject *parent)
    : QObject(parent)
    , m_enter(enter)
    , m_time(time)
{
}

CDivisionType::CDivisionType(const CDivisionType &obj)
    : QObject()
    , m_enter(obj.enter())
    , m_time(obj.time())
{
}

CDivisionType &CDivisionType::operator =(const CDivisionType &obj)
{
    enter(obj.enter());
    time(obj.time());

    return *this;
}
