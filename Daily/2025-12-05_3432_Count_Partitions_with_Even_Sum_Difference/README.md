# 3432. Count Partitions with Even Sum Difference

**Difficulty:** Easy  
**Topics:** Array, Math, Prefix Sum  
**Date:** 2025-12-05

## Problem Description

You are given an integer array `nums` of length `n`.

A partition is defined as an index `i` where `0 <= i < n - 1`, splitting the array into two non-empty subarrays such that:
*   Left subarray contains indices `[0, i]`.
*   Right subarray contains indices `[i + 1, n - 1]`.

Return the number of partitions where the difference between the sum of the left and right subarrays is **even**.

## Example 1

**Input:** `nums = [10,10,3,7,6]`  
**Output:** `4`

## Example 2

**Input:** `nums = [1,2,2]`  
**Output:** `0`

## Example 3

**Input:** `nums = [2,4,6,8]`  
**Output:** `3`

## Constraints

*   `2 <= n == nums.length <= 100`
*   `1 <= nums[i] <= 100`

## Solution Explanation

We need `|leftSum - rightSum| % 2 == 0`.

### Math Insight
Let `S = total sum`, `L = left sum`, `R = right sum = S - L`.
Difference = `L - R = L - (S - L) = 2L - S`.

For the difference to be even:
*   `(2L - S) % 2 == 0`
*   Since `2L` is always even, `2L - S` is even if and only if `S` is even.

**Key Observation:** If the total sum `S` is even, then *every* partition has an even difference. If `S` is odd, then *no* partition has an even difference.

### Algorithm
1.  Calculate total sum `S`.
2.  If `S % 2 == 0`, return `n - 1` (all `n - 1` partitions are valid).
3.  If `S % 2 == 1`, return `0`.

The provided solution iterates and checks each partition, which also works but is slightly less optimal than the direct formula.

### Complexity
*   **Time Complexity:** `O(N)`.
*   **Space Complexity:** `O(1)`.
