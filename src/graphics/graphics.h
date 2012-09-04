/**
 * @file    graphics.h
 * @date    2012-9-2T22:31:00+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Graphics init file
 *
 */

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "psongview.h"

class Graphics {
public:
    inline static void exportQML() {
        qmlRegisterType<PSongView>("RTab", 1, 0, "RSongView");
    }
};

#endif // GRAPHICS_H
