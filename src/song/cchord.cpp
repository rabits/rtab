#include "cchord.h"

CChord::CChord(qint8 length, QObject *parent)
    : QObject(parent)
    , m_firstFret()
    , m_strings()
    , m_name()
    , p_beat(NULL)
{
    for( qint8 i = 0; i < length; i++ )
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
    for( quint16 i = 0; i < obj.stringsCount(); i++ )
        fret(i, obj.fret(i));

    return *this;
}

qint8 CChord::fret(const quint8 string) const
{
    if( string < stringsCount() )
        return m_strings[string];

    log_error("Can't get fret on string %i, it not allow by length %i", string, stringsCount());
    throw EXCEPTION("Can't get fret");
}

void CChord::fret(const quint8 string, const qint8 val)
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

quint8 CChord::notesCount() const
{
    quint8 count = 0;
    foreach(qint8 fret, strings())
        if( fret > -1 ) count++;

    return count;
}
