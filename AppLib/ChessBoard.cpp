#include "Bing.h"
#include "ChessBoard.h"
#include <QDebug>
ChessBoard::ChessBoard(QObject *parent) : QObject(parent)
{
    qDebug() << "Created board";
    for (int i=0; i<5; i++){
        auto p = new Bing(this, Player::Black);
        p->setPosition(i*2, 3);
        _chessPieces.append(p);
    }
    for (int i=0; i<5; i++){
        auto p = new Bing(this, Player::Red);
        p->setPosition(i*2, 6);
        _chessPieces.append(p);
    }
}

ChessBoard::~ChessBoard()
{

}

QList<ChessPiece *> ChessBoard::chessPieces() const
{
    return _chessPieces;
}

Player ChessBoard::getPieceOn(int x, int y) const
{
    return Player::None;
}
