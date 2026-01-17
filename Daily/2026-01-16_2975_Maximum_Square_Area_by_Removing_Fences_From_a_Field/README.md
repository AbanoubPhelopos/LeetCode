# 2975. Maximum Square Area by Removing Fences From a Field

**Difficulty:** Medium  
**Date:** January 16, 2026

## Problem Description

There is a large `(m - 1) x (n - 1)` rectangular field with corners at `(1, 1)` and `(m, n)` containing some horizontal and vertical fences given in arrays `hFences` and `vFences` respectively.

Horizontal fences are from the coordinates `(hFences[i], 1)` to `(hFences[i], n)` and vertical fences are from the coordinates `(1, vFences[i])` to `(m, vFences[i])`.

Return the maximum area of a square field that can be formed by removing some fences (possibly none) or `-1` if it is impossible to make a square field.

Since the answer may be large, return it modulo `10^9 + 7`.

**Note:** The field is surrounded by two horizontal fences from the coordinates `(1, 1)` to `(1, n)` and `(m, 1)` to `(m, n)` and two vertical fences from the coordinates `(1, 1)` to `(m, 1)` and `(1, n)` to `(m, n)`. These fences cannot be removed.

### Example 1:
```
Input: m = 4, n = 3, hFences = [2,3], vFences = [2]
Output: 4
Explanation: Removing the horizontal fence at 2 and the vertical fence at 2 will give a square field of area 4.
```

### Example 2:
```
Input: m = 6, n = 7, hFences = [2], vFences = [4]
Output: -1
Explanation: It can be proved that there is no way to create a square field by removing fences.
```

## Constraints:
- `3 <= m, n <= 10^9`
- `1 <= hFences.length, vFences.length <= 600`
- `1 < hFences[i] < m`
- `1 < vFences[i] < n`
- `hFences` and `vFences` are unique.

## Solution Explanation

We want to find the largest square area, which means finding the largest common side length `S` such that there exists a horizontal gap of size `S` and a vertical gap of size `S`.

### Approach

1.  **Add Boundary Fences:**
    *   The field is bounded by `1` and `m` horizontally. Add these to `hFences`.
    *   The field is bounded by `1` and `n` vertically. Add these to `vFences`.
2.  **Calculate All Possible Gaps:**
    *   Any square region must be bounded by two horizontal fences (say at `h1` and `h2`) and two vertical fences (say at `v1` and `v2`).
    *   The height of such a region is `abs(h1 - h2)` and the width is `abs(v1 - v2)`.
    *   We can iterate through all pairs of horizontal fences to find all possible vertical spans (heights) available. Store these valid heights in a Hash Set.
    *   Similarly, iterate through all pairs of vertical fences to find all possible horizontal spans (widths) available.
3.  **Find Maximum Intersection:**
    *   While calculating the spans for the second dimension (e.g., widths), check if that span exists in the set of heights calculated previously.
    *   Track the maximum common span `maxL`.
4.  **Optimization:**
    *   To improve performance, process the dimension with fewer fences first (store its gaps in the HashSet), and then iterate through the dimension with more fences to check for existence. This reduces the number of set insertions.
5.  **Result:**
    *   If `maxL` is found, return `maxL * maxL % MOD`.
    *   Otherwise, return `-1`.

The complexity is roughly `O(H^2 + V^2)` where H and V are the number of horizontal and vertical fences respectively. Given the constraints (up to 600), this is around `3.6 * 10^5` operations, which fits well within the time limit.
