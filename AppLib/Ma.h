#ifndef MA_H
#define MA_H

#include "ChessPiece.h"

#include <QObject>

class Ma : public ChessPiece
{
public:
    Ma(QObject *parent, Player player, int x, int y);

    // ChessPiece interface
public:
    bool canMoveTo(const IBoard *board, int x, int y) const;
};

#endif // MA_H
