# 2943. Maximize Area of Square Hole in Grid

**Difficulty:** Medium  
**Topics:** Array, Sorting, Greedy  
**Date:** 2026-01-15

## Problem Description

You are given the two integers, `n` and `m` and two integer arrays, `hBars` and `vBars`. The grid has `n + 2` horizontal and `m + 2` vertical bars, creating `1 x 1` unit cells. The bars are indexed starting from 1.

You can remove some of the bars in `hBars` from horizontal bars and some of the bars in `vBars` from vertical bars. Note that other bars are fixed and cannot be removed.

Return an integer denoting the maximum area of a square-shaped hole in the grid, after removing some bars (possibly none).

## Example 1

**Input:** `n = 2, m = 1, hBars = [2,3], vBars = [2]`  
**Output:** `4`  
**Explanation:**  
The left image shows the initial grid formed by the bars. The horizontal bars are `[1,2,3,4]`, and the vertical bars are `[1,2,3]`.  
One way to get the maximum square-shaped hole is by removing horizontal bar 2 and vertical bar 2.  
This results in a hole bounded by horizontal bars 1 and 3 (height 2) and vertical bars 1 and 3 (width 2).  
Area = 2 * 2 = 4.

## Example 2

**Input:** `n = 1, m = 1, hBars = [2], vBars = [2]`  
**Output:** `4`

## Example 3

**Input:** `n = 2, m = 3, hBars = [2,3], vBars = [2,4]`  
**Output:** `4`

## Constraints

*   `1 <= n <= 10^9`
*   `1 <= m <= 10^9`
*   `1 <= hBars.length <= 100`
*   `2 <= hBars[i] <= n + 1`
*   `1 <= vBars.length <= 100`
*   `2 <= vBars[i] <= m + 1`
*   All values in `hBars` are distinct.
*   All values in `vBars` are distinct.

## Solution Explanation

We want to form the largest possible square hole. A hole is formed by removing consecutive bars.
If we remove a set of consecutive removable bars, we effectively merge the `1x1` cells adjacent to them.
Specifically, if we have `k` consecutive removable bars (e.g., bars 2, 3, 4 are removable and consecutive indices), we can remove all of them to create a gap of size `k + 1`.

### Approach

1.  **Consecutive Bars:** The key is to find the **longest sequence of consecutive bars** in `hBars` and `vBars`.
    *   Sort `hBars` and `vBars`.
    *   Iterate through the sorted arrays to find the maximum count of consecutive numbers.
    *   Let `maxH` be the maximum number of consecutive bars in `hBars`.
    *   Let `maxV` be the maximum number of consecutive bars in `vBars`.
2.  **Gap Size:** Removing `k` consecutive bars creates a gap of size `k + 1`.
    *   Max height gap possible = `maxH + 1`.
    *   Max width gap possible = `maxV + 1`.
3.  **Square Size:** To make a square, the side length must be limited by the smaller of the max height or max width.
    *   `side = min(maxH + 1, maxV + 1)`
4.  **Area:** The maximum area is `side * side`.

The implementation uses a single loop to iterate up to the maximum size of `hBars` and `vBars` to count consecutive sequences efficiently.
