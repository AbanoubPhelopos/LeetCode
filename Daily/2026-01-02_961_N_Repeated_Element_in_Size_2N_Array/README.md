# 961. N-Repeated Element in Size 2N Array

**Difficulty:** Easy  
**Topics:** Array, Hash Table  
**Date:** 2026-01-02

## Problem Description

You are given an integer array `nums` with the following properties:

*   `nums.length == 2 * n`.
*   `nums` contains `n + 1` unique values, `n` of which occur exactly once in the array.
*   Exactly one element of `nums` is repeated `n` times.

Return the element that is repeated `n` times.

## Example 1

**Input:** `nums = [1,2,3,3]`  
**Output:** `3`

## Example 2

**Input:** `nums = [2,1,2,5,3,2]`  
**Output:** `2`

## Example 3

**Input:** `nums = [5,1,5,2,5,3,5,4]`  
**Output:** `5`

## Constraints

*   `2 <= n <= 5000`
*   `nums.length == 2 * n`
*   `0 <= nums[i] <= 10^4`
*   `nums` contains `n + 1` unique elements and one of them is repeated exactly `n` times.

## Solution Explanation

Since the repeated element appears `n` times in a `2n` sized array, it occupies half of the array. The other `n` elements are all unique.

### Approach

We can take advantage of the high frequency of the repeated element. By Pigeonhole Principle, in any window of size 3 (or 4), the repeated element is likely to appear more than once if we check for adjacent or near-adjacent duplicates.

1.  **Iterate:** Loop through the array and check if the current element `nums[i]` is equal to `nums[i+1]` or `nums[i+2]`.
    *   If `nums[i] == nums[i+1]`, it's the repeated element.
    *   If `nums[i] == nums[i+2]`, it's the repeated element.
2.  **Edge Case:** If the loop finishes without returning, it means the repeated element was distributed such that it didn't satisfy the condition in the first `size-2` checks. In this specific logic, returning the last element covers the remaining possibility (e.g., if the repeated element is at the very end). Note that with density 0.5, it is mathematically guaranteed that either `nums[i] == nums[i+1]` or `nums[i] == nums[i+2]` or `nums[i] == nums[i+3]` happens, or specific boundary configurations exist. The provided solution handles checking gap 1 and 2, which is sufficient for most layouts, and handling the fallback return covers the edge cases (like `[x, 1, 2, 3, x]` etc if not caught earlier).

This heuristic approach is very efficient, typically `O(1)` on average, or `O(N)` worst case.
