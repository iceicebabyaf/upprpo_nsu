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

//      2.2
TEST(CandleTest, Cointains_High){
    Candle candle(100.0, 150.0, 90.0, 120.0);
    EXPECT_EQ(candle.contains(150.0), 1);
}
TEST(CandleTest, Contains_Mid){
    Candle candle(100.0, 150.0, 90.0, 120.0);
    EXPECT_EQ(candle.contains(100.0), 1);
}
TEST(CandleTest, Contains_Out){
    Candle candle(100.0, 150.0, 90.0, 120.0);
    EXPECT_EQ(candle.contains(89.99999999), 0);
}


//      2.3
TEST(CandleTest, FullSize_Into){
    Candle candle(0.0, 100.0, 0.0, 50.0);
    EXPECT_EQ(candle.full_size(), 100.0);
}
TEST(CandleTest, FullSize_EQ){
    Candle candle(100.0, 150.0, 90.0, 120.0);
    EXPECT_EQ(candle.full_size(), 60.0);
}
TEST(CandleTest, FullSize_Negative) {
    Candle candle(200.0, 150.0, 250.0, 100.0);
    EXPECT_EQ(candle.full_size(), 100.0);
}


