# Testing and CI/CD Guide for TwoSum Project

## Overview
This guide provides comprehensive documentation for understanding and implementing testing strategies and GitHub Actions CI/CD pipelines for the TwoSum algorithm implementation.

## Table of Contents
1. [Testing Fundamentals](#testing-fundamentals)
2. [Unit Testing with Google Test](#unit-testing-with-google-test)
3. [Test Case Design](#test-case-design)
4. [GitHub Actions CI/CD](#github-actions-cicd)
5. [Code Quality and Analysis](#code-quality-and-analysis)
6. [Performance Testing](#performance-testing)
7. [Best Practices](#best-practices)

## Testing Fundamentals

### What is Testing?
Testing is the process of evaluating software to detect differences between expected and actual behavior. For algorithms like TwoSum, testing ensures correctness, robustness, and performance.

### Types of Tests

#### 1. Unit Tests
- Test individual functions/methods in isolation
- Focus on specific functionality
- Fast execution, high coverage
- Example: Testing TwoSumHashTable.twoSum() with various inputs

#### 2. Integration Tests
- Test how different components work together
- Verify data flow between modules
- Example: Testing CMake build integration

#### 3. Acceptance Tests
- Validate that requirements are met
- Business-focused, end-to-end validation
- Example: Ensuring the algorithm meets LeetCode specifications

#### 4. Performance Tests
- Measure execution time and resource usage
- Validate algorithmic complexity claims
- Example: Testing O(n) vs O(n²) performance

### Testing Pyramid
```
End-to-End Tests (Few)
    ↕️
Integration Tests
    ↕️
Unit Tests (Many)
```

## Unit Testing with Google Test

### Google Test (GTest) Framework
GTest is a C++ testing framework that provides:
- Test discovery and execution
- Assertions and expectations
- Test fixtures
- Parameterized tests
- Mocking capabilities

### Basic Test Structure
```cpp
#include <gtest/gtest.h>
#include "twosum.h"

TEST(TestSuiteName, TestCaseName) {
    // Arrange
    TwoSumHashTable solver;
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // Act
    auto result = solver.twoSum(nums, target);

    // Assert
    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[1], 1);
}
```

### Assertions vs Expectations
- **ASSERT_***: Fail immediately if condition is false
- **EXPECT_***: Continue test execution, record failure

### Test Fixtures
```cpp
class TwoSumTest : public ::testing::Test {
protected:
    TwoSumHashTable hashSolver;
    TwoSumArray arraySolver;

    void SetUp() override {
        // Setup code before each test
    }

    void TearDown() override {
        // Cleanup code after each test
    }
};
```

### Parameterized Tests
```cpp
class TwoSumParamTest : public ::testing::TestWithParam<std::tuple<std::vector<int>, int, std::vector<int>>> {
};

TEST_P(TwoSumParamTest, ParameterizedTest) {
    auto [nums, target, expected] = GetParam();
    // Test implementation
}

INSTANTIATE_TEST_SUITE_P(
    TestCases,
    TwoSumParamTest,
    ::testing::Values(
        std::make_tuple(std::vector<int>{2, 7}, 9, std::vector<int>{0, 1}),
        // More test cases...
    )
);
```

## Test Case Design

### Equivalence Partitioning
Divide input data into valid and invalid partitions:

**Input Array Size:**
- Valid: [2, 10^4] elements
- Invalid: 0, 1, >10^4 elements

**Integer Values:**
- Valid: [-10^9, 10^9]
- Invalid: Outside this range

**Target Values:**
- Valid: Any integer (within int range)
- Invalid: None (all integers are valid)

### Boundary Value Analysis
Test at the edges of equivalence partitions:

| Boundary | Value | Expected Behavior |
|----------|-------|-------------------|
| Min array size | 2 elements | Valid solution |
| Max array size | 10^4 elements | Valid solution within time limit |
| Min integer | -10^9 | Correct arithmetic |
| Max integer | 10^9 | Correct arithmetic |
| Zero | 0 | Correct arithmetic |

### Edge Cases
1. **Empty Array**: `[]` → Return `[]`
2. **Single Element**: `[5]` → Return `[]`
3. **No Solution**: `[1, 2, 3]`, target=`10` → Return `[]`
4. **Duplicate Values**: `[3, 3]`, target=`6` → Return `[0, 1]`
5. **Negative Numbers**: `[-1, -2, 3]`, target=`1` → Return `[1, 2]`
6. **Zero Values**: `[0, 0, 1]`, target=`0` → Return `[0, 1]`

### Test Coverage Metrics

#### Statement Coverage
- Measures percentage of code statements executed
- Goal: > 90% for critical code

#### Branch Coverage
- Measures percentage of decision points tested
- Goal: > 80% for complex logic

#### Path Coverage
- Measures percentage of execution paths tested
- Goal: > 70% for algorithms

## GitHub Actions CI/CD

### What is CI/CD?
- **CI (Continuous Integration)**: Automatically build and test code changes
- **CD (Continuous Deployment)**: Automatically deploy tested code
- **GitHub Actions**: Platform for automating software workflows

### Workflow Structure
```yaml
name: CI Pipeline

on:  # Triggers
  push:
  pull_request:

jobs:  # Parallel/sequential execution
  job_name:
    runs-on: ubuntu-latest  # Execution environment
    steps:  # Sequential steps
      - name: Step name
        run: command
```

### Matrix Builds
Test across multiple environments:
```yaml
strategy:
  matrix:
    os: [ubuntu-latest, windows-latest, macos-latest]
    compiler: [gcc, clang, msvc]
```

### Common Actions
- `actions/checkout@v4`: Clone repository
- `actions/setup-python@v4`: Setup Python environment
- `actions/upload-artifact@v3`: Save build artifacts
- `codecov/codecov-action@v3`: Upload coverage reports

### Workflow Triggers
```yaml
on:
  push:
    branches: [main, develop]  # On push to specific branches
  pull_request:
    branches: [main]           # On PR to main
  workflow_dispatch:           # Manual trigger
  schedule:
    - cron: '0 0 * * 0'        # Weekly schedule
```

## Code Quality and Analysis

### Static Analysis Tools

#### Clang-Tidy
- Lints C++ code for style and potential bugs
- Configurable rules
- Integration with CMake

#### Clang-Format
- Automatic code formatting
- Consistent style across team
- Pre-commit hooks

### Code Coverage
- Measures how much code is tested
- Tools: lcov, gcov, codecov
- Goal: > 90% coverage for production code

### Memory Analysis
- Valgrind (Linux): Memory leaks, invalid access
- AddressSanitizer: Compile-time instrumentation
- LeakSanitizer: Runtime leak detection

## Performance Testing

### Time Complexity Analysis
- **TwoSumArray**: O(n²) - nested loops
- **TwoSumHashTable**: O(n) - single pass with hash table

### Benchmarking
```cpp
#include <benchmark/benchmark.h>

static void BM_TwoSumHashTable(benchmark::State& state) {
    TwoSumHashTable solver;
    std::vector<int> nums(state.range(0));
    // Setup test data...

    for (auto _ : state) {
        auto result = solver.twoSum(nums, target);
    }
}

BENCHMARK(BM_TwoSumHashTable)->Range(8, 8<<10);
```

### Profiling Tools
- **Linux**: perf, gprof
- **macOS**: Instruments
- **Windows**: Visual Studio Profiler
- **Cross-platform**: Valgrind Callgrind

## Best Practices

### Test Organization
1. **Test Files**: Mirror source file structure
2. **Naming**: `ClassNameTest.cpp` or `feature_test.cpp`
3. **Structure**: Arrange-Act-Assert pattern

### CI/CD Best Practices
1. **Fast Feedback**: Run critical tests first
2. **Parallel Execution**: Use matrix builds
3. **Caching**: Cache dependencies between runs
4. **Artifacts**: Save test results and coverage reports

### Code Quality
1. **Consistent Formatting**: Use clang-format
2. **Static Analysis**: Regular clang-tidy runs
3. **Code Reviews**: Automated checks before merge
4. **Documentation**: Keep tests and docs in sync

### Performance Guidelines
1. **Benchmark Regularly**: Track performance over time
2. **Profile First**: Identify bottlenecks before optimizing
3. **Memory Awareness**: Monitor memory usage
4. **Scalability Testing**: Test with realistic data sizes

## Learning Resources

### Books
- "The Art of Unit Testing" by Roy Osherove
- "Clean Code" by Robert C. Martin
- "Effective Modern C++" by Scott Meyers

### Online Resources
- [Google Test Documentation](https://google.github.io/googletest/)
- [GitHub Actions Documentation](https://docs.github.com/en/actions)
- [CMake Documentation](https://cmake.org/documentation/)
- [C++ Testing Best Practices](https://github.com/cpp-best-practices/cppbestpractices)

### Courses
- [Testing in C++](https://www.udemy.com/course/testing-in-cpp/)
- [Modern CMake](https://cliutils.gitlab.io/modern-cmake/)
- [GitHub Actions for CI/CD](https://www.udemy.com/course/github-actions/)

## Troubleshooting

### Common Issues

#### Tests Failing on CI but Passing Locally
- Environment differences (OS, compiler versions)
- Missing dependencies
- Path differences
- Timing issues

#### Slow CI Builds
- Cache dependencies
- Use parallel builds
- Optimize Docker images
- Split workflows

#### Code Coverage Not Uploading
- Check token permissions
- Verify file paths
- Check coverage format
- Debug with verbose output

### Debugging Techniques
1. **Reproduce Locally**: Run same commands as CI
2. **Isolate Issues**: Test individual components
3. **Add Logging**: Debug prints in tests
4. **Compare Environments**: Check system differences

## Conclusion

Effective testing and CI/CD are crucial for maintaining code quality and enabling rapid development. This guide provides the foundation for implementing comprehensive testing strategies for the TwoSum project and similar algorithmic implementations.

Key takeaways:
- Start with unit tests for core functionality
- Use CI/CD for automated validation
- Maintain high test coverage
- Monitor performance regularly
- Keep learning and adapting practices

Remember: Testing is not just about finding bugs—it's about building confidence in your code and enabling fearless refactoring and feature development.