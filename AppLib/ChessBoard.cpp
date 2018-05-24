#include "ChessBoard.h"
#include "Bing.h"
#include "Che.h"
#include "Ma.h"
#include "Shi.h"
#include "Shuai.h"
#include "Xiang.h"
#include <QDebug>

ChessBoard::ChessBoard(QObject *parent)
    : QObject(parent)
{
    qDebug() << "Created board";
    _activePlayer = Player::Red;
    reset();
}

ChessBoard::~ChessBoard() {}

void ChessBoard::reset()
{
    foreach (auto p, _chessPieces) {
        delete p;
    }
    _chessPieces.clear();
    // bing
    for (int i = 0; i < 5; i++) {
        auto p = new Bing(this, Player::Black, i * 2, 3);
        _chessPieces.append(p);
    }
    for (int i = 0; i < 5; i++) {
        auto p = new Bing(this, Player::Red, i * 2, 6);
        _chessPieces.append(p);
    }
    // shuai
    _blackShuai = new Shuai(this, Player::Black,4,0);
    _redShuai = new Shuai(this, Player::Red,4,9);
    _chessPieces.append(_blackShuai);
    _chessPieces.append(_redShuai);
    // shi
    _chessPieces.append(new Shi(this, Player::Black, 3, 0));
    _chessPieces.append(new Shi(this, Player::Black, 5, 0));
    _chessPieces.append(new Shi(this, Player::Red, 3, 9));
    _chessPieces.append(new Shi(this, Player::Red, 5, 9));

    // che
    _chessPieces.append(new Che(this, Player::Black, 0, 0));
    _chessPieces.append(new Che(this, Player::Black, 8, 0));
    _chessPieces.append(new Che(this, Player::Red, 0, 9));
    _chessPieces.append(new Che(this, Player::Red, 8, 9));

    // ma
    _chessPieces.append(new Ma(this, Player::Black, 1, 0));
    _chessPieces.append(new Ma(this, Player::Black, 7, 0));
    _chessPieces.append(new Ma(this, Player::Red, 1, 9));
    _chessPieces.append(new Ma(this, Player::Red, 7, 9));

    // xiang
    _chessPieces.append(new Xiang(this, Player::Black, 2, 0));
    _chessPieces.append(new Xiang(this, Player::Black, 6, 0));
    _chessPieces.append(new Xiang(this, Player::Red, 2, 9));
    _chessPieces.append(new Xiang(this, Player::Red, 6, 9));
}

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
    foreach (auto p, _chessPieces) {
        p->setIsSelected(false);
    }
    if (canSelect(piece)) {
        piece->setIsSelected(true);
    }
}

bool ChessBoard::isAttack(ChessPiece *piece) const
{
    auto originalSelected = getSelected();
    if (originalSelected == nullptr) {
        return false;
    }
    return originalSelected->player() != piece->player();
}

void ChessBoard::attack(ChessPiece *a, ChessPiece *b)
{
    if (a->canMoveTo(this, b->position().x(), b->position().y()) == false) {
        return;
    }
    a->setPosition(b->position());
    _chessPieces.removeOne(b);
    a->setIsSelected(false);
    nextPlayer();
    delete b;
}

Player ChessBoard::getWinner() const
{
    if (_chessPieces.contains(_blackShuai) == false) {
        return _redShuai->player();
    }
    if (_chessPieces.contains(_redShuai) == false) {
        return _blackShuai->player();
    }
    return Player::None;
}

Player ChessBoard::getPlayer(int x, int y) const
{
    QPoint pos(x, y);
    foreach (auto p, _chessPieces) {
        if (p->position() == pos) {
            return p->player();
        }
    }
    return Player::None;
}

bool ChessBoard::isShuai(int x, int y) const
{
    QPoint pos(x, y);
    return _blackShuai->position() == pos || _redShuai->position() == pos;
}

bool ChessBoard::isCrossRiver(Player player, int y) const
{
    if (player == Player::Black) {
        return y > 4;
    }
    return y < 5;
}

bool ChessBoard::isInsidePalace(Player player, int x, int y) const
{
    if(player==Player::Black){
        return (x>=3 && x<=5) && (y>=0 && y<=2);
    }
    return (x>=3 && x<=5) && (y>=7 && y<=9);
}

void ChessBoard::moveSelectedTo(const QPoint &pos)
{
    auto piece = getSelected();
    if (piece == nullptr) {
        return;
    }
    if (piece->canMoveTo(this, pos.x(), pos.y())) {
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
    if (isAttack(piece)) {
        auto attacker = this->getSelected();
        attack(attacker, piece);
    } else {
        select(piece);
    }
}

ChessPiece *ChessBoard::getPiece(int x, int y) const
{
    foreach (auto p, _chessPieces) {
        if (p->position().x() == x && p->position().y() == y) {
            return p;
        }
    }
    return nullptr;
}

Player ChessBoard::getActivePlayer() const
{
    return _activePlayer;
}

int ChessBoard::getPieceId(int x, int y) const
{
    foreach (auto p, _chessPieces) {
        if (p->position().x() == x && p->position().y() == y) {
            return p->getId();
        }
    }
    return 0;
}
