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


//      2.4
TEST(CandleTest, BodySize_Into){
    Candle candle(100.0, 150.0, 90.0, 120.0);
    EXPECT_GT(candle.body_size(), -1);
}
TEST(CandleTest, BodySize_EQ){
    Candle candle(180.0, 150.0, 90.0, 120.0);
    EXPECT_EQ(candle.body_size(), 60.0);
}
TEST(CandleTest, BodySize_Negative) {
    Candle candle(100.0, 150.0, 250.0, 200.0);
    EXPECT_EQ(candle.body_size(), 100.0);
}


//      2.5
TEST(CandleTest, IsRed_BigCloseR){
    Candle candle(100.0, 150.0, 90.0, 120.0);
    EXPECT_EQ(candle.is_red(), 0);
}
TEST(CandleTest, IsRed_EQR){
    Candle candle(100.0, 150.0, 90.0, 100);
    EXPECT_EQ(candle.is_red(), 0);
}
TEST(CandleTest, IsRed_SmallCloseR) {
    Candle candle(100.0, 150.0, 250.0, 50.0);
    EXPECT_EQ(candle.is_red(), 1);
}


//      2.6
TEST(CandleTest, IsGreen_BigCloseG){
    Candle candle(100.0, 150.0, 90.0, 120.0);
    EXPECT_EQ(candle.is_green(), 1);
}
TEST(CandleTest, IsGreen_EQG){
    Candle candle(100.0, 150.0, 90.0, 100);
    EXPECT_EQ(candle.is_green(), 0);
}
TEST(CandleTest, IsGreen_SmallCloseG) {
    Candle candle(100.0, 150.0, 250.0, 50.0);
    EXPECT_EQ(candle.is_green(), 0);
}

TEST(CandleTest, IsDoji_SlightDifference) {
    Candle candle(100.0, 150.0, 90.0, 100.0001);
    EXPECT_FALSE(candle.IsDoji());
}

