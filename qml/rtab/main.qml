/**
 * @file    main.qml
 * @date    2012-07-28T01:11:23+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Main qml module file
 *
 */

import QtQuick 1.1

Rectangle {
    height: 200
    width: 400
    Text {
        id: screen_size
        text: "Screen size: " + ctab.setting("preferences/device_screen")
    }
}
