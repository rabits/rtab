#include "cstreamtg12.h"

#include "../../../song/cvelocities.h"

CStreamTG12::CStreamTG12()
{
}

CStreamTG12::CBeatData::CBeatData(CMeasure &measure)
    : m_current_start(measure.header()->start())
    , m_voices()
{
    for(quint16 i = 0; i < CBeat::MAX_VOICES; i++)
        m_voices.insert(i, CStreamTG12::CVoiceData(measure));
}

qint64 CStreamTG12::CBeatData::currentStart()
{
    qint64 minimum_start = -1;
    for(quint16 i = 0 ; i < voicesCount() ; i++ )
    {
        if( voice(i).start() > m_current_start )
        {
            if( minimum_start < 0 || voice(i).start() < minimum_start )
                minimum_start = voice(i).start();
        }
    }
    if( minimum_start > m_current_start )
        m_current_start = minimum_start;

    return m_current_start;
}

CStreamTG12::CVoiceData::CVoiceData(CMeasure &measure)
    : m_start(measure.header()->start())
    , m_velocity(CVelocities::DEFAULT)
    , m_flags(0)
    , m_duration()
{
}
