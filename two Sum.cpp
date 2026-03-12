#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;

// Brute force approach: O(n^2) time, O(1) space
vector<int> TwoSumArray(const vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {}; // No solution found, though problem guarantees one
}

// Hash table approach: O(n) time, O(n) space
vector<int> TwoSumHashTable(const vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (map.find(complement) != map.end()) {
            return {map[complement], i};
        }
        map[nums[i]] = i;
    }
    return {}; // No solution found
}

// Test function
void runTests() {
    // Test case 1: Basic case
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1_array = TwoSumArray(nums1, target1);
    vector<int> result1_hash = TwoSumHashTable(nums1, target1);
    cout << "Test 1 - Array: [" << result1_array[0] << ", " << result1_array[1] << "]" << endl;
    cout << "Test 1 - Hash: [" << result1_hash[0] << ", " << result1_hash[1] << "]" << endl;

    // Test case 2: Negative numbers
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2_array = TwoSumArray(nums2, target2);
    vector<int> result2_hash = TwoSumHashTable(nums2, target2);
    cout << "Test 2 - Array: [" << result2_array[0] << ", " << result2_array[1] << "]" << endl;
    cout << "Test 2 - Hash: [" << result2_hash[0] << ", " << result2_hash[1] << "]" << endl;

    // Test case 3: Zero sum
    vector<int> nums3 = {0, 4, 3, 0};
    int target3 = 0;
    vector<int> result3_array = TwoSumArray(nums3, target3);
    vector<int> result3_hash = TwoSumHashTable(nums3, target3);
    cout << "Test 3 - Array: [" << result3_array[0] << ", " << result3_array[1] << "]" << endl;
    cout << "Test 3 - Hash: [" << result3_hash[0] << ", " << result3_hash[1] << "]" << endl;

    // Test case 4: Large numbers
    vector<int> nums4 = {-1, -2, -3, -4, -5};
    int target4 = -8;
    vector<int> result4_array = TwoSumArray(nums4, target4);
    vector<int> result4_hash = TwoSumHashTable(nums4, target4);
    cout << "Test 4 - Array: [" << result4_array[0] << ", " << result4_array[1] << "]" << endl;
    cout << "Test 4 - Hash: [" << result4_hash[0] << ", " << result4_hash[1] << "]" << endl;
}

int main() {
    runTests();
    return 0;
}
