#ifndef XIANG_H
#define XIANG_H

#include "ChessPiece.h"

#include <QObject>

class Xiang : public ChessPiece
{
public:
    explicit Xiang(QObject *parent, Player player, int x, int y);

    // ChessPiece interface
public:
    bool canMoveTo(const IBoard *board, int x, int y) const;
};

#endif // XIANG_H
