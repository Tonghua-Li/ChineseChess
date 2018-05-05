#include "ChessPiece.h"

ChessPiece::ChessPiece(QObject *parent, Player player, const QString &letter) :
    QObject(parent),
    _player(player),
    _letter(letter)
{

}

void ChessPiece::setPosition(int x, int y)
{
    _position.setX(x);
    _position.setY(y);
}
