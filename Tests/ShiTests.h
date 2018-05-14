#include "MockBoard.h"

#include <Shi.h>
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
using namespace testing;

TEST(ShiTest, canMoveTo)
{
    auto shi = new Shi(nullptr, Player::Black, 3, 0);
    MockBoard board;
    ON_CALL(board, getPlayer(A<int>(), A<int>())).WillByDefault(Return(Player::None));


    ASSERT_FALSE(shi->canMoveTo(&board, 5, 0));
    ASSERT_FALSE(shi->canMoveTo(&board, 5, 1));
    ASSERT_FALSE(shi->canMoveTo(&board, 5, 2));
    ASSERT_TRUE(shi->canMoveTo(&board, 4, 1));
    ASSERT_FALSE(shi->canMoveTo(&board, 4, 2));
    ASSERT_FALSE(shi->canMoveTo(&board, 3, 2));
    ASSERT_FALSE(shi->canMoveTo(&board, 3, 1));
    ASSERT_FALSE(shi->canMoveTo(&board, 4, 0));

}
