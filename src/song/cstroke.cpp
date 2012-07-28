/**
 * @file    cstroke.cpp
 * @date    2012-07-28T01:11:23+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Stroke
 *
 */

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

qint64 CStroke::getIncrementTime(const CBeat *beat) const
{
    if( beat == NULL )
        EXCEPTION("Gets NULL beat");

    qint64 duration = 0;
    if( value() > 0 )
    {
        for( quint16 v = 0; v < beat->voicesCount(); v++ )
        {
            CVoice voice = beat->voice( v );
            if( ! voice.empty() )
            {
                qint64 current_duration = voice.duration().time();
                if( duration == 0 || current_duration < duration )
                    duration = ( current_duration <= CDuration::QUARTER_TIME ? current_duration : CDuration::QUARTER_TIME );
            }
        }

        if( duration > 0 )
            return qRound64( (duration / 8.0f) * (4.0f / value()) );
    }

    return 0;
}
