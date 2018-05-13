#ifndef MATESTS_H
#define MATESTS_H
#include "MockBoard.h"

#include <Ma.h>
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
using namespace testing;

TEST(MaTest, CannotMove)
{
    auto ma = new Ma(nullptr, Player::Black, 2, 2);
    MockBoard board;
    ON_CALL(board, getPlayer(1, 2)).WillByDefault(Return(Player::Red));
    ON_CALL(board, getPlayer(3, 2)).WillByDefault(Return(Player::Red));
    ON_CALL(board, getPlayer(2, 1)).WillByDefault(Return(Player::Red));
    ON_CALL(board, getPlayer(2, 3)).WillByDefault(Return(Player::Red));

    for(int i=0; i< 5; i++){
        for(int j=0; j< 5; j++){
            ASSERT_FALSE(ma->canMoveTo(&board, 0, 0));
        }
    }
}

TEST(MaTest, CanMove){
    auto ma = new Ma(nullptr, Player::Black, 2, 2);
    MockBoard board;
    ON_CALL(board, getPlayer(A<int>(), A<int>())).WillByDefault(Return(Player::None));
    ASSERT_TRUE(ma->canMoveTo(&board, 1, 0));
    ASSERT_TRUE(ma->canMoveTo(&board, 3, 0));
    ASSERT_TRUE(ma->canMoveTo(&board, 0, 1));
    ASSERT_TRUE(ma->canMoveTo(&board, 4, 1));
    ASSERT_TRUE(ma->canMoveTo(&board, 0, 3));
    ASSERT_TRUE(ma->canMoveTo(&board, 4, 3));
    ASSERT_TRUE(ma->canMoveTo(&board, 1, 4));
    ASSERT_TRUE(ma->canMoveTo(&board, 3, 4));

}
#endif // MATESTS_H
