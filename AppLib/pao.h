#ifndef PAO_H
#define PAO_H

#include "ChessPiece.h"

#include <QObject>

class Pao : public ChessPiece
{
public:
    Pao(QObject *parent, Player player, int x, int y);

    // ChessPiece interface
public:
    bool canMoveTo(const IBoard *board, int x, int y) const;
};

#endif // MA_H
