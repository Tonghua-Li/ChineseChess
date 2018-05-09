#include "MockBoard.h"

#include <Shi.h>
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
using namespace testing;

TEST(ShiTest, CannotMoveOutOfBox)
{
    auto shi = new Shi(nullptr, Player::Black, 3, 0);
    MockBoard board;
    ON_CALL(board, getPlayer(A<int>(), A<int>())).WillByDefault(Return(Player::None));


    ASSERT_FALSE(shi->canMoveTo(&board, 5, 0));
    ASSERT_FALSE(shi->canMoveTo(&board, 5, 1));
    ASSERT_FALSE(shi->canMoveTo(&board, 5, 2));
    ASSERT_FALSE(shi->canMoveTo(&board, 4, 1));
    ASSERT_FALSE(shi->canMoveTo(&board, 4, 2));
    ASSERT_FALSE(shi->canMoveTo(&board, 3, 2));
    ASSERT_TRUE(shi->canMoveTo(&board, 3, 1));
    ASSERT_TRUE(shi->canMoveTo(&board, 4, 0));
    int xPositions[9][2] = {
        {3, 0}, {4, 0}, {5, 0},
        {3, 1}, {4, 1}, {5, 1},
        {3, 2}, {4, 2}, {5, 2},
    };
    for(int i =0; i< 9; i++){
        ASSERT_TRUE(shi->canMoveTo(&board, xPositions[i][0], xPositions[i][1]));
    }
}
