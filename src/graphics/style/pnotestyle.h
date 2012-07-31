/**
 * @file    pnotestyle.h
 * @date    2012-07-01T02:18:31+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Style - note
 *
 */

#ifndef PNOTESTYLE_H
#define PNOTESTYLE_H

#include "pstyle.h"

class PNoteStyle
    : public PStyle
{
    Q_OBJECT

public:
    explicit PNoteStyle(QObject *parent = 0);

signals:

protected:

};

#endif // PNOTESTYLE_H
