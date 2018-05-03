import QtQuick 2.0
import "Constants.js" as Const
import chess.lib 1.0

Rectangle {
    id: main
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
    ChessBoard{
        id: chessBoard
    }

    LineGridView{}
    RiverView{}
    BoardX{
        y: cellSize * 1.1
    }
    BoardX{
        y: cellSize * (Const.VERTICAL_SIZE - 2) * 1.01
    }

    Grid {
        id: dropGrid
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        columns: Const.HORIZONTAL_SIZE
        rows: Const.VERTICAL_SIZE
        Repeater {
            id: pieceHolderRepeater
            model: Const.HORIZONTAL_SIZE * Const.VERTICAL_SIZE
            DropArea {
                id: dropArea
                width: cellSize
                height: cellSize
                property alias dropProxy: dropArea
                property int i:index
                keys: ["chessPieceKey"]
                property Rectangle pieceContainer: cell
                onDropped: {
                    console.log("index")

                }

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
    Repeater{
        id: piecesRepeater
        model: chessBoard.chessPieces
        ChessPieceView{
            size: cellSize
            chessPiece: model.modelData
        }

    }

    ChessPieceView {
        id: piece
        size: cellSize
    }
    function getIndex(point){
        return point.x + point.y * Const.HORIZONTAL_SIZE
    }

    Component.onCompleted: {
        piece.parent = pieceHolderRepeater.itemAt(0).pieceContainer

        for(var i=0; i<chessBoard.chessPieces.length; i++){
            var v = piecesRepeater.itemAt(i)
            console.log(v.chessPiece)
            var index = getIndex(chessBoard.chessPieces[i].position)
            v.parent = pieceHolderRepeater.itemAt(index).pieceContainer
        }
    }
}
