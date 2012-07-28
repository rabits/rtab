/**
 * @file    clyrics.cpp
 * @date    2012-07-28T01:11:23+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Lyrics
 *
 */

#include "clyrics.h"

CLyrics::CLyrics(QObject *parent)
    : QObject(parent)
    , m_from(1)
    , m_lyrics()
{
}

CLyrics::CLyrics(const CLyrics &obj)
    : QObject()
    , m_from(obj.from())
    , m_lyrics(obj.lyrics())
{
}

CLyrics &CLyrics::operator =(const CLyrics &obj)
{
    from(obj.from());
    lyrics(obj.lyrics());

    return *this;
}

QStringList CLyrics::getLyricsBeats() const
{
    QString lyr(lyrics());
    return lyr.replace("\n", " ").replace("\r", " ").split(" ");
}
