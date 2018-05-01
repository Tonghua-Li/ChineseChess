import QtQuick 2.0

Item {
    id: root
    property int size: 10

    width: size
    height: size

    MouseArea {
        id: mouseArea

        width: size
        height: size
        anchors.centerIn: parent

        drag.target: tile

        onReleased: {

            if(tile.Drag.target!== null){
                root.parent = tile.Drag.target
            }
        }


        Rectangle {
            id: tile

            width: size
            height: size
            radius: size / 2
            color: "red"
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

            Drag.keys: ["chessPieceKey"]
            Drag.active: mouseArea.drag.active
            Drag.hotSpot.x: size / 2
            Drag.hotSpot.y: size / 2

            states: State {
                when: mouseArea.drag.active
                ParentChange {
                    target: tile
                    parent: root
                }
                AnchorChanges {
                    target: tile
                    anchors.verticalCenter: undefined
                    anchors.horizontalCenter: undefined
                }
            }
        }
    }
}
