#ifndef SHUAI_H
#define SHUAI_H

#include "ChessPiece.h"

#include <QObject>

class Shuai : public ChessPiece
{
public:
    Shuai(QObject *parent, Player player);

    // ChessPiece interface
public:
    bool canMoveTo(const IBoard *board, int x, int y) const;
};

#endif // SHUAI_H
