//TwoSumArray and TwoSumHashTable implementations
#include <unordered_set>
#include <vector>
#include <algorithm>

// Array-based implementation
class TwoSumArray {
public:
    bool findTwoSum(const std::vector<int>& nums, int target) {
        std::vector<int> sorted = nums;
        std::sort(sorted.begin(), sorted.end());
        
        int left = 0, right = sorted.size() - 1;
        while (left < right) {
            int sum = sorted[left] + sorted[right];
            if (sum == target) return true;
            if (sum < target) left++;
            else right--;
        }
        return false;
    }
};

// Hash table-based implementation
class TwoSumHashTable {
public:
    bool findTwoSum(const std::vector<int>& nums, int target) {
        std::unordered_set<int> seen;
        for (int num : nums) {
            int complement = target - num;
            if (seen.count(complement)) return true;
            seen.insert(num);
        }
        return false;
    }
};
