#include "csong.h"

CSong::CSong(QObject *parent)
    : QObject(parent)
    , m_name()
    , m_artist()
    , m_album()
    , m_author()
    , m_date()
    , m_copyright()
    , m_writer()
    , m_transcriber()
    , m_comments()
    , m_tracks()
    , m_measureHeaders()
    , m_channels()
{
}

CSong::CSong(const CSong &obj)
    : QObject()
    , m_name(obj.name())
    , m_artist(obj.artist())
    , m_album(obj.album())
    , m_author(obj.author())
    , m_date(obj.date())
    , m_copyright(obj.copyright())
    , m_writer(obj.writer())
    , m_transcriber(obj.transcriber())
    , m_comments(obj.comments())
    , m_tracks(obj.tracks())
    , m_measureHeaders(obj.measureHeaders())
    , m_channels(obj.channels())
{
}

CSong &CSong::operator =(const CSong &obj)
{
    clear();
    name(obj.name());
    artist(obj.artist());
    album(obj.album());
    author(obj.author());
    date(obj.date());
    copyright(obj.copyright());
    writer(obj.writer());
    transcriber(obj.transcriber());
    comments(obj.comments());
    channels(obj.channels());
    for( quint16 i = 0; i < obj.measureHeadersCount(); i++ )
    {
        measureHeader(i, obj.measureHeader(i));
        m_measureHeaders[i].song(this);
    }
    for( quint16 i = 0; i < obj.measureHeadersCount(); i++ )
    {
        track(i, obj.track(i));
        m_tracks[i].song(this);
    }

    return *this;
}
