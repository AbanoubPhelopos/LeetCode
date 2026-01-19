# 1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold

**Difficulty:** Medium  
**Topics:** Array, Binary Search, Matrix, Prefix Sum  
**Date:** 2026-01-19

## Problem Description

Given a `m x n` matrix `mat` and an integer `threshold`, return the maximum side-length of a square with a sum less than or equal to `threshold` or return `0` if there is no such square.

## Example 1

**Input:** `mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4`  
**Output:** `2`  
**Explanation:** The maximum side length of square with sum less than 4 is 2.

## Example 2

**Input:** `mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1`  
**Output:** `0`

## Constraints

*   `m == mat.length`
*   `n == mat[i].length`
*   `1 <= m, n <= 300`
*   `0 <= mat[i][j] <= 10^4`
*   `0 <= threshold <= 10^5`

## Solution Explanation

We need to efficiently calculate the sum of any square sub-matrix to check against the threshold. Since we need to maximize the side length, we can try possible side lengths.

### Approach: 2D Prefix Sum

1.  **Prefix Sum Matrix:**
    We build a 2D prefix sum matrix `pref` where `pref[i][j]` stores the sum of the rectangle defined by `(0,0)` and `(i-1, j-1)` in `mat`.
    The recurrence relation is:
    `pref[i][j] = mat[i-1][j-1] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1]`

2.  **Sum of Sub-matrix:**
    Using the prefix sum matrix, we can calculate the sum of any square sub-matrix with top-left `(i, j)` and side length `k` in **O(1)** time:
    Let `r1 = i`, `c1 = j`, `r2 = i + k`, `c2 = j + k`.
    `Sum = pref[r2][c2] - pref[r1][c2] - pref[r2][c1] + pref[r1][c1]`

3.  **Finding Maximum Side:**
    *   We start checking from the largest possible side length `maxSide = min(m, n)` down to `1`.
    *   For each `maxSide`, we iterate through all valid top-left positions `(i, j)`.
    *   If we find any square of size `maxSide` with `sum <= threshold`, we immediately return `maxSide` as it is the largest possible (since we are iterating downwards).
    *   If we finish checking all sizes and satisfy no condition, return `0`.

### Optimization
While the provided solution uses a linear scan for `maxSide` (from largest to smallest), resulting in `O(min(m,n) * m * n)`, we could also use **Binary Search** on the side length since the property is monotonic (if a square of size `k` exists, a square of size `k-1` definitely exists). Binary search would reduce complexity to `O(m * n * log(min(m,n)))`. However, given the constraints `m, n <= 300`, the linear scan approach is accepted.
