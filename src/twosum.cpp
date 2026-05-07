#include "twosum.h"
#include <unordered_map>

std::vector<int> TwoSumArray::twoSum(const std::vector<int>& nums, int target) {
    for (int i = 0; i < static_cast<int>(nums.size()); i++) {
        for (int j = i + 1; j < static_cast<int>(nums.size()); j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}

std::vector<int> TwoSumHashTable::twoSum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> map;

    for (int i = 0; i < static_cast<int>(nums.size()); i++) {
        int complement = target - nums[i];

        if (map.find(complement) != map.end()) {
            return {map[complement], i};
        }

        map[nums[i]] = i;
    }
    return {};
}
