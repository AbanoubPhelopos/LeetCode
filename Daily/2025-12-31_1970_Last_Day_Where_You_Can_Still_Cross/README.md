# 1970. Last Day Where You Can Still Cross

**Difficulty:** Hard  
**Topics:** Array, Binary Search, Depth-First Search, Breadth-First Search, Union Find, Matrix  
**Date:** 2025-12-31

## Problem Description

There is a 1-based binary `matrix` where `0` represents land and `1` represents water. You are given integers `row` and `col` representing the number of rows and columns in the matrix, respectively.

Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array `cells`, where `cells[i] = [ri, ci]` represents that on the `ith` day, the cell on the `ri`th row and `ci`th column (1-based coordinates) will be covered with water (i.e., changed to `1`).

You want to find the **last day** that it is possible to walk from the **top** to the **bottom** by only walking on land cells. You can start from any cell in the top row and end at any cell in the bottom row. You can only travel in the four cardinal directions (left, right, up, and down).

Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.

## Example 1

**Input:** `row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]`  
**Output:** `2`  
**Explanation:**  
The last day where it is possible to cross from top to bottom is on day 2.

## Example 2

**Input:** `row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]`  
**Output:** `1`  
**Explanation:**  
The last day where it is possible to cross from top to bottom is on day 1.

## Constraints

*   `2 <= row, col <= 2 * 10^4`
*   `4 <= row * col <= 2 * 10^4`
*   `cells.length == row * col`
*   `1 <= ri <= row`
*   `1 <= ci <= col`
*   All the values of `cells` are unique.

## Solution Explanation

We can rephrase the problem: what is the earliest day where we **cannot** cross from top to bottom?
However, it's often easier to think in **reverse**:
Instead of adding water day by day until we can't cross, let's start with the grid fully flooded (after the last day) and remove water (add land) day by day, extending backwards in time. The first moment we can cross in this reverse process corresponds to the last day we could cross in the forward process.

### Approach: Reverse Time + Union-Find (DSU)

1.  **Iterate Backwards:** We iterate through the `cells` array from the last element (last day) to the first (day 1).
2.  **Add Land:** For each cell `cells[i]`, we turn it from water to land.
    *   This corresponds to the state of the grid on **Day `i`** (since `cells[i]` turns to water on Day `i+1`, reverting it gives us the state on Day `i`).
3.  **Union:** When a cell becomes land, we check its 4 neighbors. If a neighbor is also land, we unite them using **Disjoint Set Union (DSU)**.
4.  **Virtual Nodes:** We use two virtual nodes:
    *   **Top Node (`0`):** Connected to all land cells in row 0.
    *   **Bottom Node (`row * col + 1`):** Connected to all land cells in the last row.
5.  **Check Connectivity:** After adding a cell and performing unions, if the Top Node and Bottom Node are in the same set, it means there is a path of land from top to bottom.
6.  **Result:** The first index `i` (representing Day `i`) where this connectivity occurs is our answer.

This approach is efficient, taking nearly linear time relative to the number of cells `O(row * col * alpha(row * col))`.
