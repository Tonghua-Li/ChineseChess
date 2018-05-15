#include "Shi.h"

Shi::Shi(QObject *parent, Player player, int x, int y)
    : ChessPiece(parent, player, "士", x, y)
{
    auto deltaY = _player == Player::Black ? 0 : 7;

    _movables.append(QPoint(3, 0 + deltaY));
    _movables.append(QPoint(5, 0 + deltaY));
    _movables.append(QPoint(4, 1 + deltaY));
    _movables.append(QPoint(3, 2 + deltaY));
    _movables.append(QPoint(5, 2 + deltaY));
}

bool Shi::canMoveTo(const IBoard *board, int x, int y) const
{
    Q_UNUSED(board);
    QPoint dest(x, y);
    if (_movables.contains(dest) == false) {
        return false;
    }
    return abs(_position.x() - x) == 1 && abs(_position.y() - y) == 1;
}
