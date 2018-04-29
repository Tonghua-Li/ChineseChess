#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <Greeter.h>
using namespace testing;

TEST(GreeterTest, Test1)
{
    auto greeter = new Greeter();
    ASSERT_EQ(2, greeter->Add(1,1));
}
