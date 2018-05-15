#ifndef XIANGTESTS_H
#define XIANGTESTS_H

#include "MockBoard.h"

#include <Xiang.h>
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
using namespace testing;

TEST(XiangTest, CanMove)
{
    auto p = new Xiang(nullptr, Player::Black, 4, 2);
    MockBoard board;
    ON_CALL(board, getPlayer(A<int>(), A<int>())).WillByDefault(Return(Player::None));

    ASSERT_TRUE(p->canMoveTo(&board, 2, 0));
    ASSERT_TRUE(p->canMoveTo(&board, 2, 4));
    ASSERT_TRUE(p->canMoveTo(&board, 6, 0));
    ASSERT_TRUE(p->canMoveTo(&board, 6, 4));
}

TEST(XiangTest, CanNotMoveWithBlocks){
    auto p = new Xiang(nullptr, Player::Black, 4, 2);
    MockBoard board;
    ON_CALL(board, getPlayer(3, 1)).WillByDefault(Return(Player::Black));
    ON_CALL(board, getPlayer(3, 3)).WillByDefault(Return(Player::Black));
    ON_CALL(board, getPlayer(5, 1)).WillByDefault(Return(Player::Black));
    ON_CALL(board, getPlayer(5, 3)).WillByDefault(Return(Player::Black));
    ASSERT_FALSE(p->canMoveTo(&board, 2, 0));
    ASSERT_FALSE(p->canMoveTo(&board, 2, 4));
    ASSERT_FALSE(p->canMoveTo(&board, 6, 0));
    ASSERT_FALSE(p->canMoveTo(&board, 6, 4));
}

TEST(XiangTest, CannotMoveAcrossRiver){
    auto black = new Xiang(nullptr, Player::Black, 2, 4);
    MockBoard board;
    ON_CALL(board, isCrossRiver(Player::Black, Gt(4))).WillByDefault(Return(true));
    ASSERT_FALSE(black->canMoveTo(&board, 0, 6));
    ASSERT_FALSE(black->canMoveTo(&board, 4, 6));

    ON_CALL(board, isCrossRiver(Player::Red, Lt(5))).WillByDefault(Return(true));
    auto red = new Xiang(nullptr, Player::Red, 2, 5);
    ASSERT_FALSE(red->canMoveTo(&board, 0, 3));
    ASSERT_FALSE(red->canMoveTo(&board, 4, 3));
}
#endif // XIANGTESTS_H
