#include "cstroke.h"

#include "cvoice.h"
#include "cduration.h"
#include "cbeat.h"

CStroke::CStroke(QObject *parent)
    : QObject(parent)
    , m_direction(STROKE_NONE)
    , m_value(0)
{
}

CStroke::CStroke(const CStroke &obj)
    : QObject()
    , m_direction(obj.direction())
    , m_value(obj.value())
{
}

CStroke &CStroke::operator =(const CStroke &obj)
{
    value(obj.value());
    direction(obj.direction());

    return *this;
}

int CStroke::getIncrementTime(const CBeat *beat) const
{
    if( beat == NULL )
        EXCEPTION("Gets NULL beat");

    long duration = 0;
    if( value() > 0 )
    {
        for( uint v = 0; v < beat->voicesCount(); v++ )
        {
            CVoice voice = beat->voice( v );
            if( ! voice.empty() )
            {
                long current_duration = voice.duration().time();
                if( duration == 0 || current_duration < duration )
                    duration = ( current_duration <= CDuration::QUARTER_TIME ? current_duration : CDuration::QUARTER_TIME );
            }
        }

        if( duration > 0 )
            return qRound( (duration / 8.0f) * (4.0f / value()) );
    }

    return 0;
}
