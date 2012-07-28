/**
 * @file    cstream.cpp
 * @date    2012-07-28T01:11:23+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Stream of format tg v1.2-current_svn
 *
 */

#include "cstream.h"

#include "../../song/cvelocities.h"

CStream::CStream()
{
}

CStream::CBeatData::CBeatData(CMeasure &measure)
    : m_current_start(measure.header()->start())
    , m_voices()
{
    for(quint16 i = 0; i < CBeat::MAX_VOICES; i++)
        m_voices.insert(i, CStream::CVoiceData(measure));
}

qint64 CStream::CBeatData::currentStart()
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

CStream::CVoiceData::CVoiceData(CMeasure &measure)
    : m_start(measure.header()->start())
    , m_velocity(CVelocities::DEFAULT)
    , m_flags(0)
    , m_duration()
{
}
