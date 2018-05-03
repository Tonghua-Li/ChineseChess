import QtQuick 2.0
import "Constants.js" as Const
Grid {
    id: lineGrid

    anchors.horizontalCenter: parent.horizontalCenter
    anchors.verticalCenter: parent.verticalCenter
    columns: Const.HORIZONTAL_SIZE - 1
    rows: Const.VERTICAL_SIZE - 1
    Repeater {
        model: (Const.HORIZONTAL_SIZE - 1) * (Const.VERTICAL_SIZE - 1)

        Rectangle {
            width: cellSize
            height: cellSize
            border.color: Const.BORDER_COLOR
            border.width: 1
            color: "#FCAE3F"
        }
    }
}
