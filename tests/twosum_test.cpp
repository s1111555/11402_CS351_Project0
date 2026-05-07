#include <gtest/gtest.h>
#include "twosum.h"
#include <vector>
#include <algorithm>

// Helper function to verify TwoSum results
static void verifyTwoSumResult(const std::vector<int>& nums,
                               int target,
                               const std::vector<int>& result) {
    if (result.empty()) {
        // No solution expected
        return;
    }

    ASSERT_EQ(result.size(), 2u) << "Result should contain exactly 2 indices";
    EXPECT_NE(result[0], result[1]) << "Indices should be different";
    EXPECT_LT(result[0], nums.size()) << "First index should be valid";
    EXPECT_LT(result[1], nums.size()) << "Second index should be valid";
    EXPECT_GE(result[0], 0) << "First index should be non-negative";
    EXPECT_GE(result[1], 0) << "Second index should be non-negative";
    EXPECT_EQ(nums[result[0]] + nums[result[1]], target)
        << "Sum of elements at returned indices should equal target";
}

// Test fixture for parameterized tests
class TwoSumTestFixture : public ::testing::TestWithParam<std::tuple<std::vector<int>, int, std::vector<int>>> {
protected:
    TwoSumHashTable hashSolver;
    TwoSumArray arraySolver;
};

// Parameterized test for HashTable implementation
TEST_P(TwoSumTestFixture, HashTableImplementation) {
    auto [nums, target, expected] = GetParam();

    auto result = hashSolver.twoSum(nums, target);

    if (expected.empty()) {
        EXPECT_TRUE(result.empty()) << "Expected no solution";
    } else {
        verifyTwoSumResult(nums, target, result);
        // For cases with expected results, verify we got a valid solution
        EXPECT_FALSE(result.empty()) << "Expected a solution but got none";
    }
}

// Parameterized test for Array implementation
TEST_P(TwoSumTestFixture, ArrayImplementation) {
    auto [nums, target, expected] = GetParam();

    auto result = arraySolver.twoSum(nums, target);

    if (expected.empty()) {
        EXPECT_TRUE(result.empty()) << "Expected no solution";
    } else {
        verifyTwoSumResult(nums, target, result);
        EXPECT_FALSE(result.empty()) << "Expected a solution but got none";
    }
}

// Test data for parameterized tests
INSTANTIATE_TEST_SUITE_P(
    TwoSumTests,
    TwoSumTestFixture,
    ::testing::Values(
        // Basic cases
        std::make_tuple(std::vector<int>{2, 7, 11, 15}, 9, std::vector<int>{0, 1}),
        std::make_tuple(std::vector<int>{3, 2, 4}, 6, std::vector<int>{1, 2}),

        // Negative numbers
        std::make_tuple(std::vector<int>{-3, 4, 3, 90}, 0, std::vector<int>{0, 2}),
        std::make_tuple(std::vector<int>{-1, -2, -3, -4}, -5, std::vector<int>{0, 2}),

        // Duplicate values
        std::make_tuple(std::vector<int>{3, 3}, 6, std::vector<int>{0, 1}),
        std::make_tuple(std::vector<int>{1, 1, 1, 1}, 2, std::vector<int>{0, 1}),

        // Zero values
        std::make_tuple(std::vector<int>{0, 1, 2, 0}, 0, std::vector<int>{0, 3}),
        std::make_tuple(std::vector<int>{-1, 0, 1}, 0, std::vector<int>{0, 2}),

        // Large numbers
        std::make_tuple(std::vector<int>{1000000000, -1000000000, 500000000, 500000000}, 1000000000, std::vector<int>{2, 3}),

        // No solution cases
        std::make_tuple(std::vector<int>{1, 2, 3}, 7, std::vector<int>{}),
        std::make_tuple(std::vector<int>{1}, 2, std::vector<int>{}),
        std::make_tuple(std::vector<int>{}, 5, std::vector<int>{}),

        // Edge cases
        std::make_tuple(std::vector<int>{1, 2}, 3, std::vector<int>{0, 1}),
        std::make_tuple(std::vector<int>{0, 0}, 0, std::vector<int>{0, 1})
    )
);

// Individual named tests for better readability
TEST(TwoSumHashTableTests, NormalCase) {
    TwoSumHashTable solver;
    std::vector<int> nums = {2, 7, 11, 15};
    auto result = solver.twoSum(nums, 9);
    verifyTwoSumResult(nums, 9, result);
    EXPECT_EQ(result, std::vector<int>({0, 1}));
}

TEST(TwoSumHashTableTests, NegativeNumbers) {
    TwoSumHashTable solver;
    std::vector<int> nums = {-3, 4, 3, 90};
    auto result = solver.twoSum(nums, 0);
    verifyTwoSumResult(nums, 0, result);
    EXPECT_EQ(result, std::vector<int>({0, 2}));
}

TEST(TwoSumHashTableTests, DuplicateValues) {
    TwoSumHashTable solver;
    std::vector<int> nums = {3, 3};
    auto result = solver.twoSum(nums, 6);
    verifyTwoSumResult(nums, 6, result);
    EXPECT_EQ(result, std::vector<int>({0, 1}));
}

TEST(TwoSumHashTableTests, NoSolution) {
    TwoSumHashTable solver;
    std::vector<int> nums = {1, 2, 3};
    auto result = solver.twoSum(nums, 7);
    EXPECT_TRUE(result.empty());
}

TEST(TwoSumHashTableTests, ZeroValues) {
    TwoSumHashTable solver;
    std::vector<int> nums = {0, 1, 2, 0};
    auto result = solver.twoSum(nums, 0);
    verifyTwoSumResult(nums, 0, result);
    EXPECT_EQ(result, std::vector<int>({0, 3}));
}

TEST(TwoSumHashTableTests, LargeNumbers) {
    TwoSumHashTable solver;
    std::vector<int> nums = {1000000000, -1000000000, 500000000, 500000000};
    auto result = solver.twoSum(nums, 1000000000);
    verifyTwoSumResult(nums, 1000000000, result);
    EXPECT_EQ(result, std::vector<int>({2, 3}));
}

TEST(TwoSumArrayTests, NormalCase) {
    TwoSumArray solver;
    std::vector<int> nums = {2, 7, 11, 15};
    auto result = solver.twoSum(nums, 9);
    verifyTwoSumResult(nums, 9, result);
    EXPECT_EQ(result, std::vector<int>({0, 1}));
}

TEST(TwoSumArrayTests, NegativeNumbers) {
    TwoSumArray solver;
    std::vector<int> nums = {-3, 4, 3, 90};
    auto result = solver.twoSum(nums, 0);
    verifyTwoSumResult(nums, 0, result);
    EXPECT_EQ(result, std::vector<int>({0, 2}));
}

TEST(TwoSumArrayTests, DuplicateValues) {
    TwoSumArray solver;
    std::vector<int> nums = {3, 3};
    auto result = solver.twoSum(nums, 6);
    verifyTwoSumResult(nums, 6, result);
    EXPECT_EQ(result, std::vector<int>({0, 1}));
}

TEST(TwoSumArrayTests, NoSolution) {
    TwoSumArray solver;
    std::vector<int> nums = {1, 2, 3};
    auto result = solver.twoSum(nums, 7);
    EXPECT_TRUE(result.empty());
}

TEST(TwoSumArrayTests, ZeroValues) {
    TwoSumArray solver;
    std::vector<int> nums = {0, 1, 2, 0};
    auto result = solver.twoSum(nums, 0);
    verifyTwoSumResult(nums, 0, result);
    EXPECT_EQ(result, std::vector<int>({0, 3}));
}

TEST(TwoSumArrayTests, LargeNumbers) {
    TwoSumArray solver;
    std::vector<int> nums = {1000000000, -1000000000, 500000000, 500000000};
    auto result = solver.twoSum(nums, 1000000000);
    verifyTwoSumResult(nums, 1000000000, result);
    EXPECT_EQ(result, std::vector<int>({2, 3}));
}

// Edge case tests
TEST(TwoSumEdgeCases, EmptyArray) {
    TwoSumHashTable hashSolver;
    TwoSumArray arraySolver;

    std::vector<int> empty_nums;
    auto hash_result = hashSolver.twoSum(empty_nums, 5);
    auto array_result = arraySolver.twoSum(empty_nums, 5);

    EXPECT_TRUE(hash_result.empty());
    EXPECT_TRUE(array_result.empty());
}

TEST(TwoSumEdgeCases, SingleElement) {
    TwoSumHashTable hashSolver;
    TwoSumArray arraySolver;

    std::vector<int> single_nums = {5};
    auto hash_result = hashSolver.twoSum(single_nums, 10);
    auto array_result = arraySolver.twoSum(single_nums, 10);

    EXPECT_TRUE(hash_result.empty());
    EXPECT_TRUE(array_result.empty());
}

TEST(TwoSumEdgeCases, MinimumValidArray) {
    TwoSumHashTable hashSolver;
    TwoSumArray arraySolver;

    std::vector<int> nums = {1, 2};
    auto hash_result = hashSolver.twoSum(nums, 3);
    auto array_result = arraySolver.twoSum(nums, 3);

    verifyTwoSumResult(nums, 3, hash_result);
    verifyTwoSumResult(nums, 3, array_result);
}

TEST(TwoSumEdgeCases, AllIdenticalElements) {
    TwoSumHashTable hashSolver;
    TwoSumArray arraySolver;

    std::vector<int> nums = {2, 2, 2, 2};
    auto hash_result = hashSolver.twoSum(nums, 4);
    auto array_result = arraySolver.twoSum(nums, 4);

    verifyTwoSumResult(nums, 4, hash_result);
    verifyTwoSumResult(nums, 4, array_result);
}

// Performance test (basic - more comprehensive perf tests would use benchmarking framework)
TEST(TwoSumPerformance, LargeArray) {
    TwoSumHashTable hashSolver;
    TwoSumArray arraySolver;

    // Create array with 1000 elements
    std::vector<int> nums;
    for (int i = 0; i < 1000; ++i) {
        nums.push_back(i);
    }

    // Test case: last two elements
    auto hash_result = hashSolver.twoSum(nums, 1998); // 999 + 999 = 1998
    auto array_result = arraySolver.twoSum(nums, 1998);

    verifyTwoSumResult(nums, 1998, hash_result);
    verifyTwoSumResult(nums, 1998, array_result);
}
