#include "ChessBoard.h"
#include "Bing.h"
#include "Che.h"
#include <QDebug>

ChessBoard::ChessBoard(QObject *parent)
    : QObject(parent)
{
    qDebug() << "Created board";
    _activePlayer = Player::Red;
    for (int i = 0; i < 5; i++) {
        auto p = new Che(this, Player::Black);
        p->setPosition(i * 2, 3);
        _chessPieces.append(p);
    }
    for (int i = 0; i < 5; i++) {
        auto p = new Che(this, Player::Red);
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

void ChessBoard::select(ChessPiece *piece)
{
    foreach(auto p, _chessPieces){
        p->setIsSelected(false);
    }
    if(canSelect(piece)){
        piece->setIsSelected(true);
    }
}

bool ChessBoard::isAttack(ChessPiece *piece) const {
    auto originalSelected = getSelected();
    if(originalSelected == nullptr) {return false;}
    return originalSelected->player() !=piece->player();
}

void ChessBoard::attack(ChessPiece *a, ChessPiece *b)
{
    a->setPosition(b->position());
    _chessPieces.removeOne(b);
    a->setIsSelected(false);
    nextPlayer();
    delete b;
}

Player ChessBoard::getPieceOn(int x, int y) const
{
    return Player::None;
}

void ChessBoard::moveSelectedTo(const QPoint &pos)
{
    auto piece = getSelected();
    if(piece == nullptr){return;}
    if(piece->canMoveTo(this, pos.x(), pos.y())){
        piece->setPosition(pos);
        piece->setIsSelected(false);
        nextPlayer();
    }
}

ChessPiece *ChessBoard::getSelected() const
{
    foreach (auto p, _chessPieces) {
        if (p->isSelected()) {
            return p;
        }
    }
    return nullptr;
}

void ChessBoard::onPieceClicked(ChessPiece *piece)
{
    if(isAttack(piece)){
        auto attacker = this->getSelected();
        attack(attacker, piece);
    }
    else{
        select(piece);
    }
}

ChessPiece *ChessBoard::getPiece(int x, int y) const
{
    foreach(auto p, _chessPieces){
        if(p->position().x() == x && p->position().y() == y){
            return p;
        }
    }
    return nullptr;
}

Player ChessBoard::getActivePlayer() const
{
    return _activePlayer;
}
