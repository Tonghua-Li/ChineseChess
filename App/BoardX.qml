import QtQuick 2.0
import "Constants.js" as Const

Item {
    id: topX
    anchors.horizontalCenter: parent.horizontalCenter

    width: cellSize * 2
    height: cellSize * 2
    Rectangle {
        anchors.left: parent.left
        height: cellSize * 2 * 1.414
        width: 1
        color: Const.BORDER_COLOR
        transform: Rotation {
            angle: -45
        }
    }
    Rectangle {
        anchors.right: parent.right
        height: cellSize * 2 * 1.414
        width: 1
        color: Const.BORDER_COLOR
        transform: Rotation {
            angle: 45
        }
    }
}
