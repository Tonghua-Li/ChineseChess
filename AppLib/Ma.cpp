#include "Ma.h"

Ma::Ma(QObject *parent, Player player, int x, int y)
    : ChessPiece(parent, player, "馬")
{
    setPosition(x, y);
}

bool Ma::canMoveTo(const IBoard *board, int x, int y) const
{
    auto currentX = _position.x();
    auto currentY = _position.y();
    auto deltaY = abs(y - currentY);
    auto deltaX = abs(x - currentX);
    if (deltaX != 1 || deltaY != 2) {
        return false;
    }
    if (abs(y) > abs(x)) { // Y direction
        auto p = board->getPlayer(x, y / abs(y) + currentY);
        return p == Player::None;
    }
    if (abs(x) > abs(y)) {
        auto p = board->getPlayer(x / abs(x) + currentX, y);
        return p == Player::None;
    }
    return false;
}
