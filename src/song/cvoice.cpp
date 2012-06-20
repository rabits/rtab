#include "cvoice.h"

CVoice::CVoice(const uint index, QObject *parent)
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
    for( uint i = 0; i < obj.notesCount(); i++ )
        noteAdd(obj.note(i));
    updateThisLinks();

    return *this;
}

void CVoice::updateThisLinks()
{
    for( uint i = 0; i < notesCount(); i++ )
        m_notes[i].voice(this);
}
