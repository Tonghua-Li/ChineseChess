#ifndef IBOARD_H
#define IBOARD_H
#include <QObject>

class IBoard{

public:
    virtual bool HasChessPiece(int x, int y) const = 0;
};

#endif // IBOARD_H
