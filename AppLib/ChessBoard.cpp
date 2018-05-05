#include "ChessBoard.h"
#include "Bing.h"
#include <QDebug>
ChessBoard::ChessBoard(QObject *parent)
    : QObject(parent)
{
    qDebug() << "Created board";
    _activePlayer = Player::Red;
    for (int i = 0; i < 5; i++) {
        auto p = new Bing(this, Player::Black);
        p->setPosition(i * 2, 3);
        _chessPieces.append(p);
    }
    for (int i = 0; i < 5; i++) {
        auto p = new Bing(this, Player::Red);
        p->setPosition(i * 2, 6);
        _chessPieces.append(p);
    }
}

ChessBoard::~ChessBoard() {}

QList<ChessPiece *> ChessBoard::chessPieces() const
{
    return _chessPieces;
}

void ChessBoard::nextPlayer()
{
    if (_activePlayer == Player::Red) {
        _activePlayer = Player::Black;
    } else {
        _activePlayer = Player::Red;
    }
}

bool ChessBoard::canSelect(ChessPiece *piece) const
{
    return _activePlayer == piece->player();
}

Player ChessBoard::getPieceOn(int x, int y) const
{
    return Player::None;
}

Player ChessBoard::getActivePlayer() const
{
    return _activePlayer;
}
