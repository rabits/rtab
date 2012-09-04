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
import RTab 1.0

Rectangle {
    id: main

    border.width: 0
    color: "#000"

    width:  (ctab.setting("preferences/screen_width")  > 0) ? ctab.setting("preferences/screen_width")  : 800
    height: (ctab.setting("preferences/screen_height") > 0) ? ctab.setting("preferences/screen_height") : 600

    onWidthChanged: ctab.setting("preferences/screen_width", main.width);
    onHeightChanged: ctab.setting("preferences/screen_height", main.height);

    RSongView {
        anchors.fill: parent
        anchors.margins: 10
        song: ctab.songOpen("/home/psa/Projects/rtab/tmp/test01.v121.tg")
    }

    Text {
        id: screen_size
        text: "Screen size: " + ctab.setting("preferences/device_screen")
    }
}
