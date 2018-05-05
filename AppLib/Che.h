#ifndef CHE_H
#define CHE_H

#include "ChessPiece.h"

#include <QObject>

class Che : public ChessPiece
{
    Q_OBJECT
public:
    explicit Che(QObject *parent, Player player);

    // ChessPiece interface
public:
    bool canMoveTo(const IBoard *board, int x, int y) const;

};

#endif // CHE_H
