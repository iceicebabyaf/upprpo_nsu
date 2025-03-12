#include <gtest/gtest.h>
#include "candle.h"
// open high low close


//      2.1
TEST(CandleTest, BodyContains_OpenPrice) {
    Candle candle(100.0, 150.0, 90.0, 120.0);
    EXPECT_EQ(candle.body_contains(100.0), 1);
}

TEST(CandleTest, BodyContains_ClosePrice) {
    Candle candle(100.0, 150.0, 90.0, 120.0);
    EXPECT_EQ(candle.body_contains(120.0), 1);
}

TEST(CandleTest, BodyContains_OutsideBody) {
    Candle candle(100.0, 150.0, 90.0, 120.0);
    EXPECT_EQ(candle.body_contains(130.0), 0);
}


