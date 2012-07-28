/**
 * @file    cvoice.cpp
 * @date    2012-07-28T01:11:23+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Voice
 *
 */

#include "cvoice.h"

CVoice::CVoice(const quint8 index, QObject *parent)
    : QObject(parent)
    , m_duration()
    , m_notes()
    , m_index(index)
    , m_direction(DIRECTION_NONE)
    , m_empty(true)
    , p_beat(NULL)
{
}

CVoice::CVoice(const CVoice &obj)
    : QObject()
    , m_duration(obj.duration())
    , m_notes(obj.notes())
    , m_index(obj.index())
    , m_direction(obj.direction())
    , m_empty(obj.empty())
    , p_beat(obj.beat())
{
    updateThisLinks();
}

CVoice &CVoice::operator =(const CVoice &obj)
{
    index(obj.index());
    empty(obj.empty());
    direction(obj.direction());
    duration(obj.duration());
    for( quint8 i = 0; i < obj.notesCount(); i++ )
        noteAdd(obj.note(i));
    updateThisLinks();

    return *this;
}

void CVoice::updateThisLinks()
{
    for( quint8 i = 0; i < notesCount(); i++ )
        m_notes[i].voice(this);
}
