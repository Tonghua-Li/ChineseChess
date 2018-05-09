#ifndef SHI_H
#define SHI_H

#include "ChessPiece.h"

#include <QObject>

class Shi : public ChessPiece
{
public:
    Shi(QObject *parent, Player player, int x, int y);

    // ChessPiece interface
public:
    bool canMoveTo(const IBoard *board, int x, int y) const;
private:
    QList<QPoint> _movables;
};

#endif // SHI_H
