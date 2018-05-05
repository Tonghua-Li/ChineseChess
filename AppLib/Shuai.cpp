#include "Shuai.h"

Shuai::Shuai(QObject *parent, Player player)
    :ChessPiece (parent, player, "蟀")
{
    setPosition(4, player==Player::Black?0:9);
}

bool Shuai::canMoveTo(const IBoard *board, int x, int y) const
{
    return true;
}
