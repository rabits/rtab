#include "ctrack.h"

#include "csong.h"

CTrack::CTrack(QObject *parent)
    : QObject(parent)
    , m_number(0)
    , m_offset(0)
    , m_channelId(-1)
    , m_solo(false)
    , m_mute(false)
    , m_name()
    , m_measures()
    , m_strings()
    , m_color()
    , m_lyrics()
    , p_song(NULL)
{
}

CTrack::CTrack(const CTrack &obj)
    : QObject()
    , m_number(obj.number())
    , m_offset(obj.offset())
    , m_channelId(obj.channelId())
    , m_solo(obj.solo())
    , m_mute(obj.mute())
    , m_name(obj.name())
    , m_measures(obj.measures())
    , m_strings(obj.strings())
    , m_color(obj.color())
    , m_lyrics(obj.lyrics())
    , p_song(obj.song())
{
}

CTrack &CTrack::operator =(const CTrack &obj)
{
    clear();
    number(obj.number());
    name(obj.name());
    offset(obj.offset());
    solo(obj.solo());
    mute(obj.mute());
    channelId(obj.channelId());
    color(obj.color());
    lyrics(obj.lyrics());
    strings(obj.strings());

    updateSongLinks();

    return *this;
}

void CTrack::updateSongLinks()
{
    if( song() != NULL )
    {
        for( uint i = 0; i < measuresCount(); i++ )
            m_measures[i].header(&(song()->measureHeader(i)));
    }
}
