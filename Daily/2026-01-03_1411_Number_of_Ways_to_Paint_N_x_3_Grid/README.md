# 1411. Number of Ways to Paint N × 3 Grid

**Difficulty:** Hard  
**Topics:** Dynamic Programming  
**Date:** 2026-01-03

## Problem Description

You have a grid of size `n x 3` and you want to paint each cell of the grid with exactly one of the three colors: **Red**, **Yellow**, or **Green** while making sure that no two adjacent cells have the same color (i.e., no two cells that share vertical or horizontal sides have the same color).

Given `n` the number of rows of the grid, return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed **modulo** `10^9 + 7`.

## Example 1

**Input:** `n = 1`  
**Output:** `12`  
**Explanation:** There are 12 possible way to paint the grid as shown.

## Example 2

**Input:** `n = 5000`  
**Output:** `30228214`

## Constraints

*   `n == grid.length`
*   `1 <= n <= 5000`

## Solution Explanation

This problem can be solved using **Dynamic Programming** by observing the patterns of colors in each row.

Since there are only 3 columns, we can classify the coloring of valid row into two types:
1.  **Type A (3 Colors):** All three cells in the row have different colors (e.g., `Red-Yellow-Green`, `1-2-3`).
2.  **Type B (2 Colors):** Two cells have the same color (e.g., `Red-Yellow-Red`, `1-2-1`). Note that adjacent cells cannot be same, so the first and third must be the same.

### Transitions

Let `A` be the number of ways to paint a row with Type A pattern, and `B` be the number of ways to paint a row with Type B pattern.

**Initialization (n=1):**
*   **Type A:** `3 * 2 * 1 = 6` ways (e.g., 123, 132, 213, 231, 312, 321).
*   **Type B:** `3 * 2 * 1 = 6` ways (e.g., 121, 131, 212, 232, 313, 323).

**Recurrence:**
When moving from row `i` to `i+1`, we check how many valid patterns of Type A and Type B can be generated.

1.  **From Type A (e.g., 123):**
    *   Compatible Type A next rows: `231`, `312` (2 ways).
    *   Compatible Type B next rows: `212`, `232` (2 ways).
    *   So, `1` Type A generates `2` new Type A and `2` new Type B.

2.  **From Type B (e.g., 121):**
    *   Compatible Type A next rows: `213`, `232` (Wait, `232` is B), `231` (Wait 21 vs 31 OK) -> `213`, `312` (2 ways).
    *   Compatible Type B next rows: `212`, `232`, `323` (3 ways).
    *   So, `1` Type B generates `2` new Type A and `3` new Type B.

**Formulas:**
*   `newA = 2 * A + 2 * B`
*   `newB = 2 * A + 3 * B`

We iterate `n-1` times and the answer is `(A + B) % MOD`.
