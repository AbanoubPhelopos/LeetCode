# 3583. Count Special Triplets

**Difficulty:** Medium  
**Topics:** Array, Hash Table, Counting  
**Date:** 2025-12-09

## Problem Description

A **special triplet** is defined as a triplet of indices `(i, j, k)` such that:
*   `0 <= i < j < k < n`, where `n = nums.length`
*   `nums[i] == nums[j] * 2`
*   `nums[k] == nums[j] * 2`

Return the total number of special triplets in the array, modulo `10^9 + 7`.

## Example 1

**Input:** `nums = [6,3,6]`  
**Output:** `1`  
**Explanation:** The only special triplet is `(0, 1, 2)`:
*   `nums[0] = 6 = nums[1] * 2 = 3 * 2`
*   `nums[2] = 6 = nums[1] * 2 = 3 * 2`

## Example 2

**Input:** `nums = [0,1,0,0]`  
**Output:** `1`

## Example 3

**Input:** `nums = [8,4,2,8,4]`  
**Output:** `2`

## Constraints

*   `3 <= n == nums.length <= 10^5`
*   `0 <= nums[i] <= 10^5`

## Solution Explanation

For a valid triplet `(i, j, k)`:
*   `nums[i] = nums[j] * 2` (i is before j)
*   `nums[k] = nums[j] * 2` (k is after j)

This means both `nums[i]` and `nums[k]` equal `nums[j] * 2`, so we need to count for each middle element `j`, how many elements before it are `2 * nums[j]` and how many after it are `2 * nums[j]`.

### Approach: Two Frequency Maps

1.  **Initialize:**
    *   `freqNext`: frequency map of all elements (elements to the right of current position).
    *   `freqPrev`: empty map (elements to the left of current position).
2.  **Iterate through each element as the middle element `j`:**
    *   Remove current element from `freqNext` (it's no longer to the right).
    *   Count pairs: `freqPrev[nums[j] * 2] * freqNext[nums[j] * 2]`.
    *   Add current element to `freqPrev`.

### Complexity
*   **Time Complexity:** `O(N)`.
*   **Space Complexity:** `O(N)` for the frequency maps.
