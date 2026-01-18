# 1895. Largest Magic Square

**Difficulty:** Medium  
**Topics:** Array, Matrix, Prefix Sum  
**Date:** 2026-01-18

## Problem Description

A `k x k` **magic square** is a `k x k` grid filled with integers such that every row sum, every column sum, and both diagonal sums are all equal. The integers in the magic square do not have to be distinct. Every `1 x 1` grid is trivially a magic square.

Given an `m x n` integer `grid`, return the **size** (i.e., the side length `k`) of the **largest magic square** that can be found within this grid.

## Example 1

**Input:** `grid = [[7,1,4,5,6],[2,5,1,6,4],[1,5,4,3,2],[1,2,7,3,4]]`  
**Output:** `3`  
**Explanation:**  
The largest magic square has a size of 3.  
Every row sum, column sum, and diagonal sum of this magic square is equal to 12.  
*   Row sums: `5+1+6 = 5+4+3 = 2+7+3 = 12`
*   Column sums: `5+5+2 = 1+4+7 = 6+3+3 = 12`
*   Diagonal sums: `5+4+3 = 6+4+2 = 12`

## Example 2

**Input:** `grid = [[5,1,3,1],[9,3,3,1],[1,3,3,8]]`  
**Output:** `2`

## Constraints

*   `m == grid.length`
*   `n == grid[i].length`
*   `1 <= m, n <= 50`
*   `1 <= grid[i][j] <= 10^6`

## Solution Explanation

We need to check for magic squares of all possible sizes `k`. Since we want the largest, we can iterate `k` from `min(m, n)` down to 2. If we find a magic square of size `k`, that's our answer. If we check all `k` down to 2 and find none, the answer is 1.

### Approach: Prefix Sums

Checking sums of rows, columns, and diagonals repeatedly would be slow (`O(k^2)` per square check). We can optimize this using **Prefix Sums**.

1.  **Preprocessing:**
    *   **Row Prefix Sums (`rowSum`):** Stores cumulative sum for each row to quickly calculate sum of any row segment. `rowSum[i][j+1]` stores sum of `grid[i][0...j]`.
    *   **Column Prefix Sums (`colSum`):** Stores cumulative sum for each column. `colSum[i+1][j]` stores sum of `grid[0...i][j]`.
    *   **Main Diagonal Prefix Sums (`diag`):** Stores cumulative sum along main diagonals. `diag[i+1][j+1]` stores sum along diagonal ending at `(i, j)`.
    *   **Anti-Diagonal Prefix Sums (`antidiag`):** Stores cumulative sum along anti-diagonals. `antidiag[i+1][j]` stores sum along anti-diagonal ending at `(i, j)`. Note: The indices for anti-diagonal need careful handling or a specific mapping. The provided solution uses a mapping where `antidiag[i+1][j]` likely accumulates from top-right to bottom-left relative to `(i, j)`.

2.  **Verification for Size `k`:**
    *   Iterate through all possible top-left corners `(i, j)` for a `k x k` square.
    *   **Diagonal Check:** First, check if the main diagonal sum equals the anti-diagonal sum.
        *   `Main Diag Sum = diag[i + k][j + k] - diag[i][j]`
        *   `Anti Diag Sum = antidiag[i + k][j] - antidiag[i][j + k]` (Based on the solution's logic).
    *   **Row/Column Check:** If diagonals match, verified if all rows and columns in this `k x k` subgrid have the same sum.
    *   If all conditions match, return `k`.

### Complexity
*   **Time Complexity:** `O(min(m, n) * m * n * k)`. Since `m, n <= 50`, `k` is small. The optimizations make the inner check `O(k)` instead of `O(k^2)`. Total complexity is roughly `O(m * n * min(m, n))`.
*   **Space Complexity:** `O(m * n)` for storing prefix sum arrays.

The constraints `m, n <= 50` are small enough for this approach.
