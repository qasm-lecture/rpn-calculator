#include "lib.hpp"

#include <gtest/gtest.h>

TEST(Evaluate, simple_addition_works) {
  EXPECT_EQ(2, evaluate("11+"));
}

void testSplitStringBySpace() {
    // Test 1: Basic test
    {
        std::string input = "This is a test string";
        std::vector<std::string> expected = {"This", "is", "a", "test", "string"};
        assert(splitStringBySpace(input) == expected);
    }

    // Test 2: Test empty input
    {
        std::string input = "";
        std::vector<std::string> expected = {};
        assert(splitStringBySpace(input) == expected);
    }

    // Test 3: Test input with multiple spaces between words
    {
        std::string input = "This   is a test   string";
        std::vector<std::string> expected = {"This", "is", "a", "test", "string"};
        assert(splitStringBySpace(input) == expected);
    }

    // Test 4: Test input with leading and trailing spaces
    {
        std::string input = "  This is a test string  ";
        std::vector<std::string> expected = {"This", "is", "a", "test", "string"};
        assert(splitStringBySpace(input) == expected);
    }

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  testSplitStringBySpace();
  return RUN_ALL_TESTS();
}
