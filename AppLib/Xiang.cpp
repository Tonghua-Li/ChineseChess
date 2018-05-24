#include "Xiang.h"

Xiang::Xiang(QObject *parent, Player player, int x, int y)
    : ChessPiece(parent, player, player == Player::Black ? "象" : "相", x, y,6)
{}

bool Xiang::canMoveTo(const IBoard *board, int x, int y) const
{
    if (board->isCrossRiver(_player, y)) {
        return false;
    }
    auto currX = _position.x();
    auto currY = _position.y();
    if (abs(currX - x) != 2 || abs(currY - y) != 2) {
        return false;
    }
    auto deltaXToBlock = (x - currX) / 2;
    auto deltaYToBlock = (y - currY) / 2;
    auto blockX = currX + deltaXToBlock;
    auto blockY = currY + deltaYToBlock;
    auto p = board->getPlayer(blockX, blockY);
    return p == Player::None;
}
