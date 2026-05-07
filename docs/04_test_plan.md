
# Test Plan for TwoSum Implementation

## Overview
This test plan outlines the comprehensive strategy for validating the TwoSum algorithm implementation that finds two numbers in an array that add up to a target value. The implementation includes two approaches: brute force (TwoSumArray) and optimized hash table (TwoSumHashTable).

## Test Objectives
- Verify correctness of both TwoSumArray and TwoSumHashTable implementations
- Ensure all edge cases are handled properly
- Validate performance requirements are met
- Confirm robustness against invalid inputs
- Test cross-platform compatibility

## Test Scope
- **In Scope**: Functional testing, performance testing, edge case testing
- **Out of Scope**: Security testing, load testing, integration testing with external systems

## Test Strategy

### 1. Unit Testing Approach
- Use Google Test framework (GTest) for C++ unit tests
- Test both TwoSumArray and TwoSumHashTable classes separately
- Cover all public methods and their behaviors

### 2. Test Categories

#### 2.1 Functional Tests
- **Valid Solutions**: Test cases where exactly one solution exists
- **Multiple Solutions**: Test cases where multiple pairs could work
- **No Solution**: Test cases where no valid pair exists

#### 2.2 Edge Cases
- Empty arrays
- Single element arrays
- Arrays with duplicate values
- Negative numbers and zero values
- Large integer values (near INT_MAX/INT_MIN)

#### 2.3 Boundary Tests
- Minimum array size (2 elements)
- Maximum array size (10^4 elements)
- Integer boundaries (-10^9 to 10^9)

#### 2.4 Performance Tests
- Time complexity validation
- Space complexity validation
- Large dataset handling

### 3. Test Environment
- **Development**: Local machine with CMake and GTest
- **CI/CD**: GitHub Actions with Ubuntu, Windows, and macOS runners
- **Compilers**: GCC, Clang, MSVC
- **C++ Standards**: C++17 and later

## Detailed Test Cases

### 3.1 Functional Test Cases

#### TC-FUNC-001: Basic Valid Pair (HashTable)
- **Input**: nums = [2, 7, 11, 15], target = 9
- **Expected**: [0, 1] (indices of 2 and 7)
- **Rationale**: Standard LeetCode example

#### TC-FUNC-002: Basic Valid Pair (Array)
- **Input**: nums = [2, 7, 11, 15], target = 9
- **Expected**: [0, 1] (indices of 2 and 7)
- **Rationale**: Verify brute force approach works

#### TC-FUNC-003: Negative Numbers
- **Input**: nums = [-3, 4, 3, 90], target = 0
- **Expected**: [0, 2] (indices of -3 and 3)
- **Rationale**: Test negative number handling

#### TC-FUNC-004: Duplicate Values
- **Input**: nums = [3, 3], target = 6
- **Expected**: [0, 1] (both indices valid)
- **Rationale**: Test duplicate number handling

#### TC-FUNC-005: No Solution Exists
- **Input**: nums = [1, 2, 3], target = 7
- **Expected**: [] (empty vector)
- **Rationale**: Test no-solution scenario

#### TC-FUNC-006: Large Numbers
- **Input**: nums = [1000000000, -1000000000, 500000000, 500000000], target = 1000000000
- **Expected**: [2, 3] (indices of the two 500000000s)
- **Rationale**: Test large integer handling

#### TC-FUNC-007: Zero Values
- **Input**: nums = [0, 1, 2, 0], target = 0
- **Expected**: [0, 3] (indices of the two zeros)
- **Rationale**: Test zero value handling

### 3.2 Edge Case Test Cases

#### TC-EDGE-001: Minimum Array Size
- **Input**: nums = [1, 2], target = 3
- **Expected**: [0, 1]
- **Rationale**: Test minimum valid array size

#### TC-EDGE-002: Empty Array
- **Input**: nums = [], target = 5
- **Expected**: [] (empty vector)
- **Rationale**: Test empty array handling

#### TC-EDGE-003: Single Element Array
- **Input**: nums = [5], target = 10
- **Expected**: [] (empty vector)
- **Rationale**: Test single element array

#### TC-EDGE-004: All Same Elements
- **Input**: nums = [2, 2, 2, 2], target = 4
- **Expected**: [0, 1] (any valid pair)
- **Rationale**: Test all identical elements

### 3.3 Boundary Test Cases

#### TC-BOUND-001: Maximum Array Size
- **Input**: nums = [1, 2, ..., 10000], target = 19999
- **Expected**: [9999, 9998] (last two elements)
- **Rationale**: Test maximum array size

#### TC-BOUND-002: Integer Maximum Values
- **Input**: nums = [2147483647, -2147483648, 1, -1], target = -1
- **Expected**: [1, 3] (INT_MIN and -1)
- **Rationale**: Test integer boundary values

## Test Execution

### 4.1 Manual Testing
```bash
# Build and run tests locally
cd build
cmake --build .
ctest --verbose
```

### 4.2 Automated Testing (CI/CD)
- GitHub Actions triggers on push/PR to main branch
- Tests run on Ubuntu, Windows, and macOS
- Coverage reports generated automatically

## Success Criteria
- ✅ All functional tests pass
- ✅ All edge case tests pass
- ✅ All boundary tests pass
- ✅ Performance requirements met (O(n) time for HashTable, O(n²) for Array)
- ✅ Code coverage > 90%
- ✅ No memory leaks or crashes
- ✅ Cross-platform compatibility

## Risk Assessment
- **High Risk**: Integer overflow with large values
- **Medium Risk**: Performance degradation with large arrays
- **Low Risk**: Empty/single element arrays

## Test Metrics
- Test Case Count: 15+ test cases
- Test Coverage: Statement coverage > 90%
- Performance Benchmarks: < 1ms for arrays up to 10^4 elements
- Defect Density: < 0.1 defects per test case
