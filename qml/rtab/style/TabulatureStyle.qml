/**
 * @file    TabulatureStyle.qml
 * @date    2012-07-30T14:20:50+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Style of tabulature
 *
 */

import QtQuick 1.1

Style {
    id: root

    property real leftPadding:   16
    property real rightPadding:  16
    property real topPadding:    16
    property real bottomPadding: 16

    property color backgroundColor: "#fff"
    property color foregroundColor: "#000"

    property color selectedBackgroundColor: "#000"
    property color selectedForegroundColor: "#fff"
}
