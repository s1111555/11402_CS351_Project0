#ifndef TWOSUM_H
#define TWOSUM_H

#include <vector>

class TwoSumArray {
public:
    std::vector<int> twoSum(const std::vector<int>& nums, int target);
};

class TwoSumHashTable {
public:
    std::vector<int> twoSum(const std::vector<int>& nums, int target);
};

#endif // TWOSUM_H
