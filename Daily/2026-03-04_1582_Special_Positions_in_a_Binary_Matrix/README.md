# 1582. Special Positions in a Binary Matrix

**Difficulty:** Easy  
**Topics:** Array, Matrix  
**Date:** 2026-03-04

## Problem Description

Given an `m x n` binary matrix `mat`, return the number of special positions in `mat`.

A position `(i, j)` is called special if `mat[i][j] == 1` and all other elements in row `i` and column `j` are `0` (rows and columns are 0-indexed).

**Example 1:**
```
Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
Output: 1
Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.
```

**Example 2:**
```
Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
Explanation: (0, 0), (1, 1) and (2, 2) are special positions.
```

## Constraints

*   `m == mat.length`
*   `n == mat[i].length`
*   `1 <= m, n <= 100`
*   `mat[i][j]` is either `0` or `1`.

## Solution Approach

The definitions of a special position directly implies that a cell `(i, j)` is special if its value is `1`, its entire row `i` contains exactly one `1` (which is at `j`), and its entire column `j` contains exactly one `1` (which is at `i`).

Instead of checking the row sum and column sum every time we encounter a `1` (which would take $O(n+m)$ per cell, leading to $O(m \times n \times (m+n))$ overall), we can precompute the sums of each row and each column.

1.  **Count Ones:** We use two integer arrays `row` of size `m` and `col` of size `n` to store the number of `1`s in each row and column respectively.
    *   Initialize both arrays with zeros.
    *   Iterate over the entire matrix once. If `mat[i][j] == 1`, increment `row[i]` and `col[j]`. This step takes $O(m \times n)$ time.

2.  **Find Special Positions:** Now we iterate over the matrix a second time.
    *   For each position `(i, j)`, we check if `mat[i][j] == 1`, `row[i] == 1`, and `col[j] == 1`. 
    *   If all conditions are met, `(i, j)` is a special position, and we increment our answer counter. This second iteration also takes $O(m \times n)$ time.

The total time complexity is $O(m \times n)$, which is optimal since we must traverse the entire matrix. The space complexity is $O(m + n)$ for storing the `row` and `col` sum arrays.
