# 3578. Count Partitions With Max-Min Difference at Most K

**Difficulty:** Medium  
**Topics:** Array, Dynamic Programming, Sliding Window, Monotonic Deque  
**Date:** 2025-12-06

## Problem Description

You are given an integer array `nums` and an integer `k`. Your task is to partition `nums` into one or more non-empty contiguous segments such that in each segment, the difference between its maximum and minimum elements is at most `k`.

Return the total number of ways to partition `nums` under this condition.

Since the answer may be too large, return it modulo `10^9 + 7`.

## Example 1

**Input:** `nums = [9,4,1,3,7], k = 4`  
**Output:** `6`

## Example 2

**Input:** `nums = [3,3,4], k = 0`  
**Output:** `2`

## Constraints

*   `2 <= nums.length <= 5 * 10^4`
*   `1 <= nums[i] <= 10^9`
*   `0 <= k <= 10^9`

## Solution Explanation

We use **Dynamic Programming** combined with **Sliding Window Maximum/Minimum** (using Monotonic Deques).

### DP Definition
*   `dp[i]` = number of ways to partition `nums[0...i-1]`.
*   Base case: `dp[0] = 1` (empty prefix has one way: do nothing).
*   Transition: `dp[r+1] = sum of dp[l] for all valid l` where `nums[l...r]` forms a valid segment.

### Sliding Window for Valid Segments
A segment `[l, r]` is valid if `max(nums[l...r]) - min(nums[l...r]) <= k`.
We maintain:
*   Monotonic decreasing deque `mx` for max values.
*   Monotonic increasing deque `mn` for min values.

As we expand `r`, we update the deques. If `max - min > k`, we shrink the window from the left by incrementing `l` and removing stale entries from the deques.

### Sum Optimization
Instead of summing `dp[l...r]` each time, we maintain a running sum `sum` of valid `dp` values. When `l` moves right, we subtract `dp[l]` from `sum`.

### Complexity
*   **Time Complexity:** `O(N)` — each index is pushed/popped from deques at most once.
*   **Space Complexity:** `O(N)` for `dp` array and deques.
