
# Acceptance Tests for TwoSum

## Overview
Acceptance tests for the TwoSum algorithm implementation.

## Test Cases

### TC1: Valid Pair Found
**Given:** Array `[2, 7, 11, 15]` and target `9`
**When:** TwoSum function is called
**Then:** Returns `[0, 1]` (indices of 2 and 7)

### TC2: Multiple Valid Pairs
**Given:** Array `[3, 3]` and target `6`
**When:** TwoSum function is called
**Then:** Returns `[0, 1]`

### TC3: No Valid Pair
**Given:** Array `[1, 2, 3]` and target `10`
**When:** TwoSum function is called
**Then:** Returns empty array or `[-1, -1]`

### TC4: Negative Numbers
**Given:** Array `[-1, -2, -3, 5, 10]` and target `7`
**When:** TwoSum function is called
**Then:** Returns indices of `-3` and `10`

### TC5: Single Pair
**Given:** Array `[1, 2, 3, 4]` and target `5`
**When:** TwoSum function is called
**Then:** Returns valid index pair

### TC6: Edge Case - Empty Array
**Given:** Empty array `[]`
**When:** TwoSum function is called
**Then:** Returns empty array or error

### TC7: Large Numbers
**Given:** Array with large integers
**When:** TwoSum function is called
**Then:** Correctly identifies valid pair
