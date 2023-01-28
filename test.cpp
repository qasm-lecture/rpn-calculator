#include "lib.hpp"

#include <gtest/gtest.h>

TEST(Evaluate, simple_addition_works) {
    EXPECT_EQ(0, evaluate("00+"));
    EXPECT_EQ(2, evaluate("11+"));
    EXPECT_EQ(10, evaluate("19+"));
}
TEST(Evaluate, simple_substraction_works){
    EXPECT_EQ(0, evaluate("00-"));
    EXPECT_EQ(0, evaluate("11-"));
    EXPECT_EQ(6, evaluate("93-"));
    EXPECT_EQ(-6, evaluate("39-"));
}

TEST(Evaluate, simple_divide_works){
    EXPECT_EQ(1, evaluate("11/"));
    EXPECT_EQ(3, evaluate("93/"));
    EXPECT_EQ(0, evaluate("39/"));
}

TEST(Evaluate, simple_multiply_works){
    EXPECT_EQ(0, evaluate("10*"));
    EXPECT_EQ(1, evaluate("11*"));
    EXPECT_EQ(81, evaluate("99*"));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
