/**
 * @file    pnote.h
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

#ifndef PNOTE_H
#define PNOTE_H

#include "pbasic.h"
#include "style/pnotestyle.h"

class PNote
    : public PBasic
{
    Q_OBJECT

public:
    explicit PNote(PNoteStyle *style, QDeclarativeItem *parent = 0);

signals:

protected:

};

#endif // PNOTE_H
