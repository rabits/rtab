#include "cmeasure.h"

CMeasure::CMeasure(CMeasureHeader *header, QObject *parent)
    : QObject(parent)
    , m_clef(DEFAULT_CLEF)
    , m_keySignature(DEFAULT_KEY_SIGNATURE)
    , m_beats()
    , p_header(header)
    , p_track(NULL)
{
}

CMeasure::CMeasure(const CMeasure &obj)
    : QObject()
    , m_clef(obj.clef())
    , m_keySignature(obj.keySignature())
    , m_beats(obj.beats())
    , p_header(obj.header())
    , p_track(NULL)
{
    updateThisLinks();
}

CMeasure &CMeasure::operator =(const CMeasure &obj)
{
    m_beats.clear();
    clef(obj.clef());
    keySignature(obj.keySignature());
    beats(obj.beats());
    updateThisLinks();

    return *this;
}

void CMeasure::updateThisLinks()
{
    for( uint i = 0; i < beatsCount(); i++ )
        m_beats[i].measure(this);
}
