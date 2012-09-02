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

class PNote
    : public PBasic
{
    Q_OBJECT

public:
    explicit PNote(QDeclarativeItem *parent = 0);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *opts, QWidget *);

signals:

protected:

};

#endif // PNOTE_H
