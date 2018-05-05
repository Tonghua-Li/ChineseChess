#ifndef BING_H
#define BING_H

#include "ChessPiece.h"

#include <QObject>

class Bing : public ChessPiece
{
    Q_OBJECT
public:
    explicit Bing(QObject *parent, Player player);

    // ChessPiece interface
public:
    bool canMoveTo(const IBoard *board, int x, int y) const;

};

#endif // BING_H
