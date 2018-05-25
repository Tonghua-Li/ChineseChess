#ifndef MOCKBOARD_H
#define MOCKBOARD_H
#include "gmock/gmock.h"

#include <IBoard.h>
class MockBoard: public IBoard{
public:
    MOCK_CONST_METHOD2(getPlayer, Player(int x, int y));
    MOCK_CONST_METHOD2(isShuai, bool(int x, int y));
    MOCK_CONST_METHOD2(isCrossRiver, bool(Player player, int y));
    MOCK_CONST_METHOD3(isInsidePalace, bool(Player player, int x, int y));
    MOCK_CONST_METHOD2(getPieceId, int(int x, int y));
};
#endif // MOCKBOARD_H
