# 3623. Count Number of Trapezoids I

**Difficulty:** Medium  
**Topics:** Array, Hash Table, Math, Combinatorics  
**Date:** 2025-12-02

## Problem Description

You are given a 2D integer array `points`, where `points[i] = [xi, yi]` represents the coordinates of the `ith` point on the Cartesian plane.

A **horizontal trapezoid** is a convex quadrilateral with at least one pair of horizontal sides (i.e., parallel to the x-axis). Two lines are parallel if and only if they have the same slope.

Return the number of unique horizontal trapezoids that can be formed by choosing any four distinct points from `points`.

Since the answer may be very large, return it modulo `10^9 + 7`.

## Example 1

**Input:** `points = [[1,0],[2,0],[3,0],[2,2],[3,2]]`  
**Output:** `3`

## Example 2

**Input:** `points = [[0,0],[1,0],[0,1],[2,1]]`  
**Output:** `1`

## Constraints

*   `4 <= points.length <= 10^5`
*   `–10^8 <= xi, yi <= 10^8`
*   All points are pairwise distinct.

## Solution Explanation

A horizontal trapezoid requires two horizontal sides (parallel to the x-axis). For a side to be horizontal, both endpoints must have the same y-coordinate.

### Approach: Count Pairs of Horizontal Segments

1.  **Group by Y-Coordinate:** Count how many points share each y-coordinate. Store this in a frequency map `freq[y] = count`.
2.  **Count Horizontal Pairs:** For each y-coordinate with `f` points:
    *   The number of ways to choose 2 points on this line (forming a horizontal segment) is `C(f, 2) = f * (f - 1) / 2`.
    *   Let `c_y = C(f_y, 2)` for y-level `y`.
3.  **Count Trapezoids:** A trapezoid is formed by picking one horizontal segment from y-level `y1` and another from y-level `y2` where `y1 != y2`.
    *   Total ways to pick 2 segments from any 2 different y-levels:
        *   `sum = Σ c_y` (sum of all pairs)
        *   Total pairs of pairs: `sum * (sum - 1) / 2`... but this overcounts pairs from the *same* y-level.
    *   Alternative formula: `(sum^2 - Σ(c_y^2)) / 2`
        *   `sum^2` counts all ordered pairs `(seg1, seg2)`.
        *   `Σ(c_y^2)` counts pairs where both segments are from the same y-level (which don't form valid trapezoids).
        *   Dividing by 2 makes it unordered pairs.

### Complexity
*   **Time Complexity:** `O(N)` for iterating through points and then the frequency map.
*   **Space Complexity:** `O(N)` for the frequency map.
