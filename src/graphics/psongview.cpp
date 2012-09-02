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
{
}

void PSongView::paint(QPainter *painter, const QStyleOptionGraphicsItem *opts, QWidget *)
{
    painter->save();

    painter->setRenderHint(QPainter::Antialiasing, style().smooth());
    painter->setPen(style().borderColor());
    painter->setBrush(style().backgroundColor());
    painter->drawEllipse(opts->rect);
    if( song() != NULL )
        painter->drawText(opts->rect, song()->name());

    painter->restore();
}
