/**
 * @file    psongview.cpp
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

#include "psongview.h"

PSongView::PSongView(QDeclarativeItem *parent)
    : PBasic(parent)
    , m_song(NULL)
    , m_track(0)
{
}

void PSongView::paint(QPainter *painter, const QStyleOptionGraphicsItem *opts, QWidget *)
{
    log_debug("Start Song painter");
    painter->save();

    painter->setRenderHint(QPainter::Antialiasing, style().smooth());

    // Draw container
    painter->setPen(style().borderColor());
    painter->setBrush(style().backgroundColor());
    painter->drawRect(opts->rect);

    if( song() != NULL )
    {
        QRect track_rect = opts->rect;
        track_rect.setLeft(track_rect.left() + style().leftPadding());
        track_rect.setRight(track_rect.right() - style().rightPadding());
        track_rect.setTop(track_rect.top() + style().topPadding());
        track_rect.setBottom(track_rect.bottom() - style().bottomPadding());

        paintTrack(painter, track_rect);
    }

    painter->restore();
}

void PSongView::paintTrack(QPainter *painter, const QRect &rect)
{
    if( track() >= song()->tracksCount() )
        throw EXCEPTION(log_error("No track with number %i to paint it", track()));

    CTrack *current_track = &(song()->track(track()));

    // Draw container
    painter->save();
    painter->setBrush(style().backgroundColor());
    painter->setPen(QPen(Qt::DashDotLine));
    painter->drawRect(rect);
    painter->restore();

    for( quint8 i = 0; i < current_track->stringsCount(); i++ )
    {
        qint16 string_top = rect.top() + style().topPadding() + i*5;
        painter->drawLine(QPoint(rect.left() + style().leftPadding(), string_top)
                        , QPoint(rect.right() - style().rightPadding(), string_top));
    }
}
