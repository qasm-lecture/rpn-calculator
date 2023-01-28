#include "lib.hpp"
#include <stdexcept>
#include <gtest/gtest.h>

TEST(Evaluate, simple_addition_works) {
    int counter = 1;
    EXPECT_FLOAT_EQ(0, evaluate("00+", counter));
    EXPECT_FLOAT_EQ(2, evaluate("11+", counter));
    EXPECT_FLOAT_EQ(10, evaluate("19+", counter));
}

TEST(Evaluate, simple_substraction_works){
    int counter = 1;
    EXPECT_FLOAT_EQ(0.0, evaluate("00-", counter));
    EXPECT_FLOAT_EQ(0.0, evaluate("11-", counter));
    EXPECT_FLOAT_EQ(6.0, evaluate("93-", counter));
    EXPECT_FLOAT_EQ(-6.0, evaluate("39-", counter));
}

TEST(Evaluate, simple_divide_works){
    int counter = 1;
    EXPECT_FLOAT_EQ(1.0f, evaluate("11/", counter));
    EXPECT_FLOAT_EQ(3.0f, evaluate("93/", counter));
    EXPECT_FLOAT_EQ(3.0/9.0, evaluate("39/", counter));
}

TEST(Evaluate, simple_divide_fails){
    int counter = 1;
    EXPECT_THROW(evaluate("00/", counter), std::invalid_argument);
}

TEST(Evaluate, simple_multiply_works){
    int counter = 1;
    EXPECT_FLOAT_EQ(0.0, evaluate("10*", counter));
    EXPECT_FLOAT_EQ(1.0, evaluate("11*", counter));
    EXPECT_FLOAT_EQ(81.0, evaluate("99*", counter));
}

TEST(Evaluate, simple_ln_works) {
    int counter = 1;
    EXPECT_FLOAT_EQ(ln(9), evaluate("9l", counter));
}

TEST(Evaluate, simple_exp_works) {
    int counter = 1;
    EXPECT_FLOAT_EQ(exponential(2.0), evaluate("2e", counter));
}

TEST(Evaluate, simple_square_works) {
    int counter = 1;
    EXPECT_FLOAT_EQ(16.0, evaluate("4s", counter));
}

TEST(Evaluate, simple_sqrt_works) {
    int counter = 1;
    EXPECT_FLOAT_EQ(3.0, evaluate("9q", counter));
}

TEST(SplitStringsBySpace, basic_input_works) {
  std::string input = "This is a test string";
  std::vector<std::string> expected = {"This", "is", "a", "test", "string"};
  EXPECT_EQ(splitStringBySpace(input), expected);
}

TEST(SplitStringsBySpace, empty_input_works) {
  std::string input = "";
  std::vector<std::string> expected = {};
  EXPECT_EQ(splitStringBySpace(input), expected);
}

TEST(SplitStringsBySpace, multiple_and_leading_spaces_works) {
  std::string input = "  This   is a test   string";
  std::vector<std::string> expected = {"This", "is", "a", "test", "string"};
  EXPECT_EQ(splitStringBySpace(input), expected);
}

TEST(ISSTRINGNUMBER, positiveNumber_works) {
  std::string input = "123";
  EXPECT_TRUE(isStringNumber(input));
}

TEST(ISSTRINGNUMBER, negativeNumber_works) {
  std::string input = "-323";
  EXPECT_TRUE(isStringNumber(input));
}

TEST(ISSTRINGNUMBER, decimal_works) {
  std::string input = "0.324";
  EXPECT_TRUE(isStringNumber(input));
}

TEST(ISSTRINGNUMBER, not_a_number_works) {
    std::string input = "notanumber";
    EXPECT_FALSE(isStringNumber(input));
}
TEST(Evaluate, invalid_input_fails) {
    int counter = 1;
    EXPECT_THROW(evaluate("-", counter),  std::invalid_argument);
    EXPECT_THROW(evaluate("1*", counter),  std::invalid_argument);
    EXPECT_THROW(evaluate("blub", counter),  std::invalid_argument);
    EXPECT_THROW(evaluate("b/", counter),  std::invalid_argument);
    EXPECT_THROW(evaluate("1w3+", counter),  std::invalid_argument);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
