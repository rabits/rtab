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

qint64 CDuration::time() const
{
    qint64 time = (QUARTER_TIME * (4.0f / value()));
    if( dotted() )
        time += time / 2;
    else if( doubleDotted() )
        time += (time / 4) * 3;

    return divisionType().convertTime(time);
}

CDuration CDuration::fromTime(qint64 in_time) const
{
    CDuration minDuration;
    minDuration.value(SIXTY_FOURTH);
    minDuration.divisionType(CDivisionType::TRIPLET);

    return fromTime(in_time, minDuration);
}

CDuration CDuration::fromTime(qint64 in_time, CDuration minDuration, qint32 diff) const
{
    CDuration tmpDuration;
    tmpDuration.value(WHOLE);
    tmpDuration.dotted(true);

    bool finish = false;
    while(!finish)
    {
        qint64 tmpTime = tmpDuration.time();
        if( (tmpTime - diff) <= in_time )
        {
            if( qAbs<qint64>(tmpTime - in_time) < qAbs<qint64>(minDuration.time() - in_time) )
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

qint16 CDuration::index() const
{
    qint16 index = 0;
    qint16 val = value();
    while( (val = (val >> 1)) > 0 )
        index++;

    return index;
}
