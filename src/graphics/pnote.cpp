/**
 * @file    pnote.cpp
 * @date    2012-07-01T02:18:31+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Paint object - note
 *
 */

#include "pnote.h"

PNote::PNote(PNoteStyle *style, QDeclarativeItem *parent)
    : PBasic(style, parent)
{
    setFlag(QGraphicsItem::ItemHasNoContents, false);
}
