#include "Shuai.h"

Shuai::Shuai(QObject *parent, Player player)
    : ChessPiece(parent, player, player==Player::Black? "將":"帥", 4, player == Player::Black ? 0 : 9)
{}

bool Shuai::canMoveTo(const IBoard *board, int x, int y) const
{
    return true;
}
