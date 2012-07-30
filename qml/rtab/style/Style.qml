/**
 * @file    Style.qml
 * @date    2012-07-30T16:16:00+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Basic style
 *
 */

import QtQuick 1.1

QtObject {
    id: styleClass
    property bool inverted: theme.inverted? true : false
    property string __invertedString: inverted? "-inverted" : ""
}
