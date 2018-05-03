#include "Bing.h"
#include "ChessBoard.h"
#include <QDebug>
ChessBoard::ChessBoard(QObject *parent) : QObject(parent)
{
    qDebug() << "Created board";
    for (int i=0; i<5; i++){
        auto p = new Bing(this);
        _chessPieces.append(p);
    }
}
