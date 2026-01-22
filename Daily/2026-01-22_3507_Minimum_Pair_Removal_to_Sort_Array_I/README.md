# 3507. Minimum Pair Removal to Sort Array I

**Difficulty:** Easy  
**Topics:** Array, Simulation, Greedy  
**Date:** 2026-01-22

## Problem Description

Given an array `nums`, you can perform the following operation any number of times:
*   Select the adjacent pair with the **minimum sum** in `nums`. If multiple such pairs exist, choose the leftmost one.
*   Replace the pair with their sum.

Return the minimum number of operations needed to make the array **non-decreasing**.

## Example 1

**Input:** `nums = [5,2,3,1]`  
**Output:** `2`  
**Explanation:**  
1.  `(3,1)` has min sum 4 → `[5,2,4]`
2.  `(2,4)` has min sum 6 → `[5,6]`

## Example 2

**Input:** `nums = [1,2,2]`  
**Output:** `0`

## Constraints

*   `1 <= nums.length <= 50`
*   `-1000 <= nums[i] <= 1000`

## Solution Explanation

This is a direct **simulation** problem. Given the small constraints (`n <= 50`), we can afford a brute-force approach.

### Algorithm
1.  **Check Sorted:** If `nums` is already non-decreasing, return 0.
2.  **Find Min Pair:** Iterate through all adjacent pairs, find the one with minimum sum (leftmost if tie).
3.  **Merge:** Replace the pair at position `pos` with `nums[pos] + nums[pos+1]` and erase `nums[pos+1]`.
4.  **Repeat:** Increment operation count and repeat until sorted.

### Complexity
*   **Time Complexity:** `O(N^3)` in the worst case — up to `O(N)` operations, each requiring `O(N)` to find min pair and `O(N)` to erase.
*   **Space Complexity:** `O(1)` extra space.

Given `N <= 50`, this is efficient enough.
