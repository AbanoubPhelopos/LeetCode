# 1877. Minimize Maximum Pair Sum in Array

**Difficulty:** Medium  
**Topics:** Array, Greedy, Sorting, Two Pointers  
**Date:** 2026-01-23

## Problem Description

The **pair sum** of a pair `(a, b)` is equal to `a + b`. The max pair sum is the largest pair sum in a list of pairs.
Given an array `nums` of even length `n`, pair up the elements of `nums` into `n / 2` pairs such that:
1.  Each element of `nums` is in exactly one pair, and
2.  The maximum pair sum is minimized.

Return the minimized maximum pair sum after optimally pairing up the elements.

## Example 1

**Input:** `nums = [3,5,2,3]`  
**Output:** `7`  
**Explanation:** The elements can be paired up into pairs `(3,3)` and `(5,2)`. Max pair sum is `max(6, 7) = 7`.

## Example 2

**Input:** `nums = [3,5,4,2,4,6]`  
**Output:** `8`  
**Explanation:** The elements can be paired up into pairs `(3,5), (4,4), (6,2)`. Max pair sum is `max(8, 8, 8) = 8`.

## Constraints

*   `n == nums.length`
*   `2 <= n <= 10^5`
*   `n` is even.
*   `1 <= nums[i] <= 10^5`

## Solution Explanation

To minimize the maximum pair sum, we should pair the smallest element with the largest element, the second smallest with the second largest, and so on.

### Approach 1: Sorting (O(N log N))
1.  Sort the array `nums` in ascending order.
2.  Pair `nums[i]` with `nums[n-1-i]`.
3.  The answer is `max(nums[i] + nums[n-1-i])` for all `0 <= i < n/2`.

### Approach 2: Counting Sort / Frequency Array (O(N + K))
Since the range of numbers is small (`1 <= nums[i] <= 100,000`), we can use a frequency array (Counting Sort idea) to avoid `O(N log N)` sorting.
1.  Count frequencies of each number.
2.  Use two pointers: `l` starting from `min_val` and `r` starting from `max_val`.
3.  Match the smallest available number (`l`) with the largest available number (`r`).
4.  Update `max_sum` and decrement counts.
5.  Move `l` right if its count is 0, and `r` left if its count is 0.

This approach is `O(N + K)` where `K` is the range of values, which is faster for large `N`. The provided solution uses this optimized approach.

### Complexity
*   **Time Complexity:** `O(N + K)` using counting sort logic.
*   **Space Complexity:** `O(K)` for the frequency array.
