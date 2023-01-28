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

TEST(Evaluate, simple_divide_fails){
EXPECT_ANY_THROW(evaluate("00/"));
}

TEST(Evaluate, simple_multiply_works){
EXPECT_EQ(0, evaluate("10*"));
EXPECT_EQ(1, evaluate("11*"));
EXPECT_EQ(81, evaluate("99*"));
}
TEST(Evaluate, invalid_input_fails){
EXPECT_ANY_THROW(evaluate("-"));
EXPECT_ANY_THROW(evaluate("1*"));
EXPECT_ANY_THROW(evaluate("blub"));
EXPECT_ANY_THROW(evaluate("b/"));
}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
