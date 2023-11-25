#include "LibraryCode.hpp"
#include <gtest/gtest.h>
#include <iostream>

#include "LibraryCode.hpp"
#include <gtest/gtest.h>

// TEST(TestSuiteName, TestName)
TEST(TestCountPositives, BasicTest) {
    // Arrange
    std::vector<int> inputVector{1, -2, 3, -4, 5, -6, -7};

    // Act
    int count = countPositives(inputVector);

    // Assert
    ASSERT_EQ(3, count);
}

TEST(TestCountPositives, EmptyVectorTest) {
    // Arrange
    std::vector<int> inputVector{};

    // Act
    int count = countPositives(inputVector);

    // Assert
    ASSERT_EQ(0, count);
}

TEST(TestCountPositives, AllNegativesTest) {

    // Arrange
    std::vector<int> inputVector{-1, -2, -3};

    // Act
    int count = countPositives(inputVector);

    // Assert
    ASSERT_EQ(0, count);
}

// https://google.github.io/googletest/primer.html#writing-the-main-function
// Most users should not need to write their own main function and instead link with gtest_main (as opposed to with gtest), which defines a suitable entry point.
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}