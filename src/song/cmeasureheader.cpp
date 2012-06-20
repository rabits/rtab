#include "cmeasureheader.h"

#include "cduration.h"

CMeasureHeader::CMeasureHeader(QObject *parent)
    : QObject(parent)
    , m_number(0)
    , m_start(CDuration::QUARTER_TIME)
    , m_timeSignature()
    , m_tempo()
    , m_repeatOpen(false)
    , m_repeatAlternative(0)
    , m_repeatClose(0)
    , m_tripletFeel(TRIPLET_FEEL_NONE)
    , p_marker(NULL)
    , p_song(NULL)
{
    markerCheck();
}

CMeasureHeader::CMeasureHeader(const CMeasureHeader &obj)
    : QObject()
    , m_number(obj.number())
    , m_start(obj.start())
    , m_timeSignature(obj.timeSignature())
    , m_tempo(obj.tempo())
    , m_repeatOpen(obj.repeatOpen())
    , m_repeatAlternative(obj.repeatAlternative())
    , m_repeatClose(obj.repeatClose())
    , m_tripletFeel(obj.tripletFeel())
    , p_marker(obj.marker())
    , p_song(obj.song())
{
    markerCheck();
}

CMeasureHeader &CMeasureHeader::operator =(const CMeasureHeader &obj)
{
    number(obj.number());
    start(obj.start());
    repeatOpen(obj.repeatOpen());
    repeatAlternative(obj.repeatAlternative());
    repeatClose(obj.repeatClose());
    tripletFeel(obj.tripletFeel());
    timeSignature(obj.timeSignature());
    tempo(obj.tempo());
    marker(obj.markerHas() ? obj.marker() : NULL);

    return *this;
}
