#include "cduration.h"

CDuration::CDuration(QObject *parent)
    : QObject(parent)
    , m_value(QUARTER)
    , m_dotted(false)
    , m_doubleDotted(false)
    , m_divisionType()
{
}

CDuration::CDuration(const CDuration &obj)
    : QObject()
    , m_value(obj.value())
    , m_dotted(obj.dotted())
    , m_doubleDotted(obj.doubleDotted())
    , m_divisionType(obj.divisionType())
{
}

CDuration &CDuration::operator =(const CDuration &obj)
{
    value(obj.value());
    dotted(obj.dotted());
    doubleDotted(obj.doubleDotted());
    divisionType(obj.divisionType());

    return *this;
}

long CDuration::time() const
{
    long time = (QUARTER_TIME * (4.0f / value()));
    if( dotted() )
        time += time / 2;
    else if( doubleDotted() )
        time += (time / 4) * 3;

    return divisionType().convertTime(time);
}

CDuration CDuration::fromTime(long in_time) const
{
    CDuration minDuration;
    minDuration.value(SIXTY_FOURTH);
    minDuration.divisionType(CDivisionType::TRIPLET);

    return fromTime(in_time, minDuration);
}

CDuration CDuration::fromTime(long in_time, CDuration minDuration, int diff) const
{
    CDuration tmpDuration;
    tmpDuration.value(WHOLE);
    tmpDuration.dotted(true);

    bool finish = false;
    while(!finish)
    {
        long tmpTime = tmpDuration.time();
        if( (tmpTime - diff) <= in_time )
        {
            if( qAbs<long>(tmpTime - in_time) < qAbs<long>(minDuration.time() - in_time) )
                minDuration = tmpDuration;
        }
        if( tmpDuration.dotted() )
            tmpDuration.dotted(false);
        else if( tmpDuration.divisionType() == CDivisionType::NORMAL )
            tmpDuration.divisionType(CDivisionType::TRIPLET);
        else
        {
            tmpDuration.value(tmpDuration.value() * 2);
            tmpDuration.dotted(true);
            tmpDuration.divisionType(CDivisionType::NORMAL);
        }
        if( tmpDuration.value() > CDuration::SIXTY_FOURTH )
            finish = true;
    }

    return minDuration;
}

int CDuration::index() const
{
    int index = 0;
    int val = value();
    while( (val = (val >> 1)) > 0 )
        index++;

    return index;
}
