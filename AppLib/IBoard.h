#ifndef IBOARD_H
#define IBOARD_H

#include <QObject>

class IBoard{

public:
    virtual ~IBoard(){}
    virtual int hasPieceOn(int x, int y) const = 0;
};

#endif // IBOARD_H
