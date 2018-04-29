import QtQuick 2.0
import "Constants.js" as Const

Rectangle {
    width: parent.height < parent.width ? parent.height / Const.VERTICAL_SIZE
                                          * Const.HORIZONTAL_SIZE : parent.width
    height: parent.height > parent.width ? parent.width / Const.HORIZONTAL_SIZE
                                           * Const.VERTICAL_SIZE : parent.height
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.verticalCenter: parent.verticalCenter
    border.color: Const.BORDER_COLOR
    border.width: Const.BORDER_WIDTH

    color: Const.BOARD_BACKGROUND
    property int cellSize: (width > height ? height : width) / Const.VERTICAL_SIZE
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

    Item {
        id: topX
        anchors.horizontalCenter: parent.horizontalCenter
        y: cellSize * 1.1
        width: cellSize * 2
        height: cellSize * 2
        Rectangle {
            anchors.left: parent.left
            height: cellSize * 2 * 1.414
            width: 1
            color: "black"
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
    Item {
        id: bottomX
        anchors.horizontalCenter: parent.horizontalCenter
        y: cellSize * (Const.VERTICAL_SIZE - 2) * 1.01
        width: cellSize * 2
        height: cellSize * 2
        Rectangle {
            anchors.left: parent.left
            height: cellSize * 2 * 1.414
            width: 1
            color: "black"
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

    Grid {
        id: dropGrid
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        columns: Const.HORIZONTAL_SIZE
        rows: Const.VERTICAL_SIZE
        Repeater {
            model: Const.HORIZONTAL_SIZE * Const.VERTICAL_SIZE
            DropArea {
                id: dropArea
                width: cellSize
                height: cellSize
                Rectangle {
                    id: cell
                    anchors.fill: parent
                    border.color: "transparent"
                    border.width: 1
                    color: "transparent"
                    states: [
                        State {
                            when: dropArea.containsDrag
                            PropertyChanges {
                                target: cell
                                color: "grey"
                            }
                        }
                    ]
                }
            }
        }
    }
}
