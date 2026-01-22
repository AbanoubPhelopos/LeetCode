# 3531. Count Covered Buildings

**Difficulty:** Medium  
**Topics:** Array, Hash Table  
**Date:** 2025-12-11

## Problem Description

You are given a positive integer `n`, representing an `n x n` city. You are also given a 2D grid `buildings`, where `buildings[i] = [x, y]` denotes a unique building located at coordinates `[x, y]`.

A building is **covered** if there is at least one building in all four directions: left, right, above, and below.

Return the number of covered buildings.

## Example 1

**Input:** `n = 3, buildings = [[1,2],[2,2],[3,2],[2,1],[2,3]]`  
**Output:** `1`  
**Explanation:** Only building `[2,2]` is covered.

## Example 2

**Input:** `n = 3, buildings = [[1,1],[1,2],[2,1],[2,2]]`  
**Output:** `0`

## Example 3

**Input:** `n = 5, buildings = [[1,3],[3,2],[3,3],[3,5],[5,3]]`  
**Output:** `1`

## Constraints

*   `2 <= n <= 10^5`
*   `1 <= buildings.length <= 10^5`
*   `1 <= x, y <= n`
*   All coordinates of buildings are unique.

## Solution Explanation

A building at `(x, y)` is covered if:
*   There exists a building to the **left** (same row, smaller x).
*   There exists a building to the **right** (same row, larger x).
*   There exists a building **above** (same column, smaller y).
*   There exists a building **below** (same column, larger y).

### Approach: Precompute Min/Max

1.  **Precompute:**
    *   `minx[y]`, `maxx[y]`: min and max x-coordinates among buildings in row `y`.
    *   `miny[x]`, `maxy[x]`: min and max y-coordinates among buildings in column `x`.
2.  **Check Each Building:**
    *   Building `(x, y)` is covered if `minx[y] < x < maxx[y]` AND `miny[x] < y < maxy[x]`.
    *   This means there's at least one building with smaller x in the same row (left), one with larger x (right), and similarly for column (above/below).

### Complexity
*   **Time Complexity:** `O(N)` where N is the number of buildings.
*   **Space Complexity:** `O(n)` for the min/max arrays.
