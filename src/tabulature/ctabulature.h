/**
 * @file    ctabulature.h
 * @date    2012-07-27T17:58:18+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Tabulature
 *
 */

#ifndef CTABULATURE_H
#define CTABULATURE_H

#include "src/common/common.h"

#include <QObject>

class CTabulature
    : public QObject
{
    Q_OBJECT
public:
    explicit CTabulature(QObject *parent = 0);
};

#endif // CTABULATURE_H
