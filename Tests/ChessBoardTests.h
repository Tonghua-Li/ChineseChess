#include "MockBoard.h"

#include <ChessBoard.h>
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
using namespace testing;

TEST(ChessBoardTest, isCrossRiver)
{
    auto board = new ChessBoard(nullptr);
    for(int i=0; i< 5; i++){
        ASSERT_FALSE(board->isCrossRiver(Player::Black, i));
    }
    for(int i=5; i< 9; i++){
        ASSERT_TRUE(board->isCrossRiver(Player::Black, i));
    }
    for(int i=0; i< 5; i++){
        ASSERT_TRUE(board->isCrossRiver(Player::Red, i));
    }
    for(int i=5; i< 9; i++){
        ASSERT_FALSE(board->isCrossRiver(Player::Red, i));
    }


}
