#include "ChessPiece.h"

bool ChessPiece::canMoveTo(int x, int y)
{
    return x > 5;
}

ChessPiece::ChessPiece(QObject *parent) : QObject(parent)
{

}

bool ChessPiece::CanMoveTo(const IBoard *board, int x, int y) const
{
    Q_UNUSED(board);
    Q_UNUSED(x);
    Q_UNUSED(y);
}
