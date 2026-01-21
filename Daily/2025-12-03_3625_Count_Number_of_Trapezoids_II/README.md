# 3625. Count Number of Trapezoids II

**Difficulty:** Hard  
**Topics:** Array, Hash Table, Math, Geometry  
**Date:** 2025-12-03

## Problem Description

You are given a 2D integer array `points` where `points[i] = [xi, yi]` represents the coordinates of the `ith` point on the Cartesian plane.

Return the number of unique **trapezoids** that can be formed by choosing any four distinct points from `points`.

A trapezoid is a convex quadrilateral with **at least one pair of parallel sides**. Two lines are parallel if and only if they have the same slope.

## Example 1

**Input:** `points = [[-3,2],[3,0],[2,3],[3,2],[2,-3]]`  
**Output:** `2`

## Example 2

**Input:** `points = [[0,0],[1,0],[0,1],[2,1]]`  
**Output:** `1`

## Constraints

*   `4 <= points.length <= 500`
*   `–1000 <= xi, yi <= 1000`
*   All points are pairwise distinct.

## Solution Explanation

Unlike the "Horizontal Trapezoids" problem, here any pair of parallel sides counts. This requires counting pairs of segments with the same slope.

### Approach: Inclusion-Exclusion on Segment Pairs

We iterate through all pairs of points `(i, j)` forming segments. For each segment, we track:
1.  **Slope:** Normalized `(dy/gcd, dx/gcd)`.
2.  **Line Equation:** Normalized coefficients `(a, b, c)` for `ax + by + c = 0`.
3.  **Midpoint:** `(x0 + x1, y0 + y1)` (doubled to avoid fractions).

### Counting Logic (Inclusion-Exclusion)

For each new segment `(i, j)`:
*   **`+ slope[...]`**: Pairs of segments with the same slope *could* form a trapezoid.
*   **`- coeff[...]`**: But if they lie on the *same line* (collinear), they don't form a valid quadrilateral. Subtract these.
*   **`- midPoint[...]`**: Pairs of segments sharing the same midpoint (with different slopes) form a **parallelogram**. Since parallelograms have *two* pairs of parallel sides, they are counted twice by the slope logic. Subtract once.
*   **`+ midPointWslope[...]`**: But if two segments share both midpoint AND slope, they are already subtracted by `coeff` (collinear), so we've over-subtracted. Add them back.

### Complexity
*   **Time Complexity:** `O(N^2)` for iterating all segment pairs.
*   **Space Complexity:** `O(N^2)` for the hash maps.
