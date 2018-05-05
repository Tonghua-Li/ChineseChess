#ifndef IBOARD_H
#define IBOARD_H

#include <QObject>
#include "Player.h"

class IBoard{

public:
    virtual ~IBoard(){}
    virtual Player getPlayer(int x, int y) const = 0;
};

#endif // IBOARD_H
