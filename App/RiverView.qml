import QtQuick 2.0

import "Constants.js" as Const
Rectangle {
    id: river
    anchors.verticalCenter: parent.verticalCenter
    anchors.horizontalCenter: parent.horizontalCenter
    border.width: 1
    border.color: Const.BORDER_COLOR
    height: cellSize
    width: cellSize * (Const.HORIZONTAL_SIZE - 1)
    color: "#FCAE3F"
}
