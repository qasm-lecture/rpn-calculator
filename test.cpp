#include "lib.hpp"

#include <gtest/gtest.h>

TEST(Evaluate, simple_addition_works) {
  EXPECT_EQ(2, evaluate("11+"));
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

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
