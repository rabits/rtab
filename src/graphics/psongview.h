/**
 * @file    psongview.h
 * @date    2012-08-12T18:14:00+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   SongView - song viewer
 *
 */

#ifndef PSONGVIEW_H
#define PSONGVIEW_H

#include "pbasic.h"

#include <QRect>

#include "../song/csong.h"

class PSongView
    : public PBasic
{
    Q_OBJECT
    Q_PROPERTY(CSong* song     READ song WRITE song NOTIFY songChanged)
    Q_PROPERTY(quint8 track    READ track WRITE track NOTIFY trackChanged)

public:
    explicit PSongView(QDeclarativeItem *parent = 0);

    // --API--- //
    inline CSong* song()   const { return m_song; }
    inline quint8 track()  const { return m_track; }

    inline void song(CSong *val)  { if( m_song == val ) return; m_song = val; emit songChanged(); emit update(); }
    inline void track(quint8 val) { if( m_track == val ) return; m_track = val; emit trackChanged(); emit update(); }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *opts, QWidget *);

signals:
    void songChanged();
    void trackChanged();

protected:
    void paintTrack(QPainter *painter, const QRect &rect);
    CSong  *m_song;
    quint8  m_track;
};

#endif // PSONGVIEW_H
