# 1523. Count Odd Numbers in an Interval Range

**Difficulty:** Easy  
**Topics:** Math  
**Date:** 2025-12-07

## Problem Description

Given two non-negative integers `low` and `high`. Return the count of odd numbers between `low` and `high` (inclusive).

## Example 1

**Input:** `low = 3, high = 7`  
**Output:** `3`  
**Explanation:** The odd numbers between 3 and 7 are `[3,5,7]`.

## Example 2

**Input:** `low = 8, high = 10`  
**Output:** `1`  
**Explanation:** The odd numbers between 8 and 10 are `[9]`.

## Constraints

*   `0 <= low <= high <= 10^9`

## Solution Explanation

We need to count odd numbers in `[low, high]`.

### Math Insight
The number of odd numbers from 0 to `n` (exclusive) is `n / 2`.
*   From 0 to 10: odds are 1,3,5,7,9 → 5 = 10/2.
*   From 0 to 11: odds are 1,3,5,7,9 → 5 = 11/2.

To count odds in `[low, high]`:
*   Count odds in `[0, high]` (inclusive of high if odd).
*   Subtract odds in `[0, low)` (exclusive of low).

### Algorithm
1.  If `low` is odd, decrement it (so `[0, low)` becomes `[0, low-1]` which is just `low/2` odds).
2.  If `high` is odd, increment it (so `[0, high]` inclusive becomes `(high+1)/2` odds).
3.  Return `high/2 - low/2`.

Alternative formula: `(high + 1) / 2 - low / 2`.

### Complexity
*   **Time Complexity:** `O(1)`.
*   **Space Complexity:** `O(1)`.
