#include "ChessPiece.h"

ChessPiece::ChessPiece(QObject *parent, Player player, const QString &letter, int x, int y, int id)
    : QObject(parent)
    , _position(QPoint(x, y))
    , _player(player)
    , _letter(letter)
    , _id(id)
{}

void ChessPiece::setPosition(int x, int y)
{
    _position.setX(x);
    _position.setY(y);
}

bool ChessPiece::isSelected() const
{
    return _isSelected;
}

void ChessPiece::setIsSelected(bool isSelected)
{
    _isSelected = isSelected;
}

bool ChessPiece::isPassRiver(int y) const
{
    bool passRiver = false;
    if (_player == Player::Red) {
        passRiver = (y <= 4);
    }
    if (_player == Player::Black) {
        passRiver = (y >= 5);
    }
    return passRiver;
}

bool ChessPiece::isForward(int y) const
{
    if (_player == Player::Red) {
        return y < _position.y();
    }
    if (_player == Player::Black) {
        return y > _position.y();
    }
    return false;
}

int ChessPiece::getId() const{return _id;}
