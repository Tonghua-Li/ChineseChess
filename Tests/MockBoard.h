#ifndef MOCKBOARD_H
#define MOCKBOARD_H
#include "gmock/gmock.h"

#include <IBoard.h>
class MockBoard: public IBoard{
public:
    MOCK_CONST_METHOD2(getPlayer, Player(int x, int y));
};
#endif // MOCKBOARD_H
