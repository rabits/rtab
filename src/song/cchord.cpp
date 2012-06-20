#include "cchord.h"

CChord::CChord(int length, QObject *parent)
    : QObject(parent)
    , m_firstFret()
    , m_strings()
    , m_name()
    , p_beat(NULL)
{
    for( int i = 0; i < length; i++ )
        m_strings[i] = -1;
}

CChord::CChord(const CChord &obj)
    : QObject()
    , m_firstFret(obj.firstFret())
    , m_strings(obj.strings())
    , m_name(obj.name())
    , p_beat(obj.beat())
{
}

CChord &CChord::operator =(const CChord &obj)
{
    name(obj.name());
    firstFret(obj.firstFret());
    for( uint i = 0; i < obj.stringsCount(); i++ )
        fret(i, obj.fret(i));

    return *this;
}

int CChord::fret(const uint string) const
{
    if( string < stringsCount() )
        return m_strings[string];

    log_error("Can't get fret on string %i, it not allow by length %i", string, stringsCount());
    throw EXCEPTION("Can't get fret");
}

void CChord::fret(const uint string, const int val)
{
    if( string < stringsCount() )
    {
        m_strings[string] = val;
        emit stringsChanged();
        return;
    }

    log_error("Can't set fret on string %i, it not allow by length %i", string, stringsCount());
    throw EXCEPTION("Can't set fret");
}

uint CChord::notesCount() const
{
    uint count = 0;
    foreach(int fret, strings())
        if( fret > -1 ) count++;

    return count;
}
