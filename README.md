# TwoSum Algorithm Implementation

[![CI](https://github.com/s1111555/11402_CS351_Project0/actions/workflows/test.yml/badge.svg)](https://github.com/s1111555/11402_CS351_Project0/actions/workflows/test.yml)
[![CTest](https://github.com/s1111555/11402_CS351_Project0/actions/workflows/test.yml/badge.svg?branch=main)](https://github.com/s1111555/11402_CS351_Project0/actions/workflows/test.yml)

## Problem Statement

Given an array of integers `nums` and an integer `target`, return the indices of the two numbers that add up to the target. You may assume that each input has exactly one solution, and you cannot use the same element twice.

### Example
```cpp
Input: nums = [2, 7, 11, 15], target = 9
Output: [0, 1]  // Because nums[0] + nums[1] == 9
```

## Implementation

This project provides two different implementations of the TwoSum algorithm:

### 1. TwoSumArray (Brute Force)
- **Time Complexity**: O(n²)
- **Space Complexity**: O(1)
- **Approach**: Nested loops to check all pairs

### 2. TwoSumHashTable (Optimized)
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)
- **Approach**: Single pass with hash table lookup

## Project Structure

```
├── CMakeLists.txt          # CMake build configuration
├── src/
│   ├── twosum.h           # Class declarations
│   └── twosum.cpp         # Implementation
├── tests/
│   └── twosum_test.cpp    # Comprehensive test suite
├── docs/                   # Documentation
│   ├── 01_plan.md
│   ├── 02_SRS.md         # Software Requirements Specification
│   ├── 03_SDS.md         # Software Design Specification
│   ├── 04_test_plan.md   # Detailed test plan
│   ├── 05_acceptance_tests.md  # Acceptance test cases
│   ├── 06_traceability.md
│   ├── 07_deploy.md
│   ├── 08_known_issues.md
│   └── 09_testing_guide.md     # Comprehensive testing guide
├── build/                 # Build directory (generated)
└── .github/
    └── workflows/
        └── test.yml       # GitHub Actions CI/CD pipeline
```

## Building and Testing

### Prerequisites
- CMake 3.14+
- C++17 compatible compiler (GCC, Clang, MSVC)
- Git

### Quick Start

1. **Clone the repository**
   ```bash
   git clone https://github.com/s1111555/11402_CS351_Project0.git
   cd 11402_CS351_Project0
   ```

2. **Build the project**
   ```bash
   mkdir build && cd build
   cmake ..
   cmake --build .
   ```

3. **Run tests**
   ```bash
   ctest --verbose
   ```

### Manual Testing

You can also run the test executable directly:
```bash
cd build
./twosum_test.exe
```

## Test Coverage

The project includes comprehensive test coverage with **45 test cases** covering:

### Functional Tests
- ✅ Basic valid pairs
- ✅ Multiple solution scenarios
- ✅ Negative numbers
- ✅ Duplicate values
- ✅ Zero values
- ✅ Large numbers (near INT limits)

### Edge Cases
- ✅ Empty arrays
- ✅ Single element arrays
- ✅ No solution scenarios
- ✅ All identical elements
- ✅ Minimum/maximum array sizes

### Performance Tests
- ✅ Large array handling (1000+ elements)
- ✅ Time complexity validation

## CI/CD Pipeline

The project uses GitHub Actions for automated testing across multiple platforms:

### Supported Platforms
- **Ubuntu** (GCC, Clang)
- **Windows** (MSVC)
- **macOS** (Clang)

### Pipeline Features
- **Automated Builds**: CMake configuration and compilation
- **Cross-Platform Testing**: Multi-OS matrix builds
- **Code Quality**: Clang-tidy static analysis
- **Code Coverage**: LCOV coverage reports
- **Test Results**: JUnit XML output for CI dashboards

### Triggers
- Push to `main` or `develop` branches
- Pull requests to `main` or `develop`
- Manual workflow dispatch

## Usage Examples

### Using TwoSumHashTable (Recommended)
```cpp
#include "twosum.h"

TwoSumHashTable solver;
std::vector<int> nums = {2, 7, 11, 15};
int target = 9;
auto result = solver.twoSum(nums, target);
// result = [0, 1]
```

### Using TwoSumArray
```cpp
#include "twosum.h"

TwoSumArray solver;
std::vector<int> nums = {2, 7, 11, 15};
int target = 9;
auto result = solver.twoSum(nums, target);
// result = [0, 1]
```

## Algorithm Analysis

### TwoSumArray
```cpp
// Time: O(n²), Space: O(1)
for (int i = 0; i < nums.size(); i++) {
    for (int j = i + 1; j < nums.size(); j++) {
        if (nums[i] + nums[j] == target) {
            return {i, j};
        }
    }
}
```

### TwoSumHashTable
```cpp
// Time: O(n), Space: O(n)
std::unordered_map<int, int> map;
for (int i = 0; i < nums.size(); i++) {
    int complement = target - nums[i];
    if (map.count(complement)) {
        return {map[complement], i};
    }
    map[nums[i]] = i;
}
```

## Documentation

Comprehensive documentation is available in the `docs/` directory:

- **[Software Requirements Specification](docs/02_SRS.md)**: Functional and non-functional requirements
- **[Software Design Specification](docs/03_SDS.md)**: Implementation design and architecture
- **[Test Plan](docs/04_test_plan.md)**: Detailed testing strategy and test cases
- **[Acceptance Tests](docs/05_acceptance_tests.md)**: Business-focused validation tests
- **[Testing Guide](docs/09_testing_guide.md)**: Complete guide to testing and CI/CD concepts

## Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

### Development Setup
```bash
# Install dependencies (Ubuntu)
sudo apt-get install cmake build-essential

# Install dependencies (macOS)
brew install cmake

# Clone and build
git clone https://github.com/s1111555/11402_CS351_Project0.git
cd 11402_CS351_Project0
mkdir build && cd build
cmake ..
cmake --build .
ctest --verbose
```

## Performance Benchmarks

| Implementation | Time Complexity | Space Complexity | Typical Performance |
|----------------|----------------|------------------|-------------------|
| TwoSumArray | O(n²) | O(1) | ~500μs for n=1000 |
| TwoSumHashTable | O(n) | O(n) | ~50μs for n=1000 |

## Known Issues and Limitations

- Integer overflow not handled for extreme values
- No input validation in production code (assumes valid inputs per problem constraints)
- Hash table implementation uses std::unordered_map (may have worst-case O(n²) in rare cases)

## License

This project is part of CS351 coursework. See individual files for licensing information.

## Learning Outcomes

This project demonstrates:
- ✅ Algorithm design and analysis
- ✅ Multiple implementation approaches
- ✅ Comprehensive unit testing
- ✅ CI/CD pipeline implementation
- ✅ Cross-platform development
- ✅ Documentation best practices
- ✅ Test-driven development (TDD)

---

**Test Status**: ✅ All 45 tests passing
**CI/CD Status**: ✅ Automated testing enabled
**Coverage**: ✅ Comprehensive test suite
**Platforms**: ✅ Ubuntu, Windows, macOS