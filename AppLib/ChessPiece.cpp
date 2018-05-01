#include "ChessPiece.h"

bool ChessPiece::canMoveTo(int x, int y)
{
    return x > 5;
}

ChessPiece::ChessPiece(QObject *parent) : QObject(parent)
{

}
