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
    height: 200
    width: 400

    RSongView {
        anchors.fill: parent
        song: ctab.songOpen("/home/psa/Projects/rtab/tmp/test01.v121.tg")
    }

    Text {
        id: screen_size
        text: "Screen size: " + ctab.setting("preferences/device_screen")
    }
}
