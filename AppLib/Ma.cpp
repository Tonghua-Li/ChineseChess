#include "Ma.h"

Ma::Ma(QObject *parent, Player player, int x, int y)
    : ChessPiece(parent, player, "馬") {
  setPosition(x, y);
}

bool Ma::canMoveTo(const IBoard *board, int x, int y) const {
  auto currentX = _position.x();
  auto currentY = _position.y();
  auto deltaY = y - currentY;
  auto deltaX = x - currentX;
  if (abs(deltaX * deltaY) != 2) {
    return false;
  }
  if (abs(deltaY) > abs(deltaX)) {  // Y direction
    auto p = board->getPlayer(x, deltaY / abs(deltaY) + currentY);
    return p == Player::None;
  }
  if (abs(deltaY) < abs(deltaX)) {
    auto p = board->getPlayer(deltaX / abs(deltaX) + currentX, y);
    return p == Player::None;
  }
  return false;
}
