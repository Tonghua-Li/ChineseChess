#include "Bing.h"

Bing::Bing(QObject *parent, Player player):
    ChessPiece(parent, player, "兵")
{

}

bool Bing::canMoveTo(const IBoard *board, int x, int y) const
{
    Q_UNUSED(board);
    auto currentX = _position.x();
    auto currentY = _position.y();
    if(currentX == x){
        return abs(currentY - y) == 1;
    }
    if(currentY == y){
        return abs(currentX - x) == 1;
    }
    return false;
}
