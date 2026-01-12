# 85. Maximal Rectangle

**Difficulty:** Hard  
**Topics:** Array, Dynamic Programming, Stack, Matrix, Monotonic Stack  
**Date:** 2026-01-11

## Problem Description

Given a `rows x cols` binary `matrix` filled with `0`'s and `1`'s, find the largest rectangle containing only `1`'s and return its area.

## Example 1

**Input:** `matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]`  
**Output:** `6`  
**Explanation:** The maximal rectangle is shown in the above picture.

## Example 2

**Input:** `matrix = [["0"]]`  
**Output:** `0`

## Example 3

**Input:** `matrix = [["1"]]`  
**Output:** `1`

## Constraints

*   `rows == matrix.length`
*   `cols == matrix[i].length`
*   `1 <= rows, cols <= 200`
*   `matrix[i][j]` is `'0'` or `'1'`.

## Solution Explanation

The problem can be reduced to the "Largest Rectangle in Histogram" problem.

1.  **Histogram Construction:** We iterate through each row of the matrix. For each row, we treat it as the base of a histogram where the height of each bar is the number of consecutive 1s ending at that row in that column.
    *   If `matrix[i][j] == '1'`, then `height[j] += 1` (extends the bar from the previous row).
    *   If `matrix[i][j] == '0'`, then `height[j] = 0` (reset the bar).

2.  **Max Area Calculation:** For each updated row (histogram), we calculate the largest rectangle area that can be formed using a **Monotonic Stack**.
    *   The stack keeps track of indices of increasing heights.
    *   When we encounter a bar shorter than the one at the stack top, it limits the rectangle's extension to the right. We pop from the stack and calculate the area with the popped height as the minimum height.
    *   The width is determined by the distance between the current index and the new stack top (after popping).

3.  **Result:** The maximum area found across all rows is the answer.
