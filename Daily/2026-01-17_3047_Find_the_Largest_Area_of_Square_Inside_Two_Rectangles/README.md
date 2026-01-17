# 3047. Find the Largest Area of Square Inside Two Rectangles

**Difficulty:** Medium  
**Topics:** Array, Math, Geometry  
**Date:** 2026-01-17

## Problem Description

There exist `n` rectangles in a 2D plane with edges parallel to the x and y axis. You are given two 2D integer arrays `bottomLeft` and `topRight` where `bottomLeft[i] = [a_i, b_i]` and `topRight[i] = [c_i, d_i]` represent the bottom-left and top-right coordinates of the `ith` rectangle, respectively.

You need to find the **maximum area of a square** that can fit inside the **intersecting region of at least two rectangles**. Return `0` if such a square does not exist.

## Example 1

**Input:** `bottomLeft = [[1,1],[2,2],[3,1]], topRight = [[3,3],[4,4],[6,6]]`  
**Output:** `1`  
**Explanation:**  
A square with side length 1 can fit inside either the intersecting region of rectangles 0 and 1 or the intersecting region of rectangles 1 and 2. Hence the maximum area is 1.

## Example 2

**Input:** `bottomLeft = [[1,1],[1,3],[1,5]], topRight = [[5,5],[5,7],[5,9]]`  
**Output:** `4`  
**Explanation:**  
A square with side length 2 can fit inside either the intersecting region of rectangles 0 and 1 or the intersecting region of rectangles 1 and 2. Hence the maximum area is `2 * 2 = 4`.

## Example 3

**Input:** `bottomLeft = [[1,1],[2,2],[1,2]], topRight = [[3,3],[4,4],[3,4]]`  
**Output:** `1`  
**Explanation:**  
A square with side length 1 can fit inside the intersecting region of any two rectangles. Also, no larger square can, so the maximum area is 1.

## Example 4

**Input:** `bottomLeft = [[1,1],[3,3],[3,1]], topRight = [[2,2],[4,4],[4,2]]`  
**Output:** `0`  
**Explanation:**  
No pair of rectangles intersect, hence, the answer is 0.

## Constraints

*   `n == bottomLeft.length == topRight.length`
*   `2 <= n <= 10^3`
*   `bottomLeft[i].length == topRight[i].length == 2`
*   `1 <= bottomLeft[i][0], bottomLeft[i][1] <= 10^7`
*   `1 <= topRight[i][0], topRight[i][1] <= 10^7`
*   `bottomLeft[i][0] < topRight[i][0]`
*   `bottomLeft[i][1] < topRight[i][1]`

## Solution Explanation

To find the largest square inside the intersection of *at least two* rectangles, we can iterate through all finding pairs of rectangles and check their intersection.

### Intersection Logic

For any two rectangles `i` and `j`, their intersection (if any) is also a rectangle.
The coordinates of the intersection rectangle `[x1, y1]` (bottom-left) to `[x2, y2]` (top-right) are given by:
*   `x1 = max(bottomLeft[i][0], bottomLeft[j][0])`
*   `y1 = max(bottomLeft[i][1], bottomLeft[j][1])`
*   `x2 = min(topRight[i][0], topRight[j][0])`
*   `y2 = min(topRight[i][1], topRight[j][1])`

### Valid Intersection

The intersection is valid (non-empty area) if `x2 > x1` and `y2 > y1`.
*   Width of intersection: `width = x2 - x1`
*   Height of intersection: `height = y2 - y1`

### Largest Square

The largest square that fits inside this intersection rectangle has a side length equal to the **minimum** of its width and height.
*   `side = min(width, height)`

We iterate through all possible pairs `(i, j)` where `i < j`, calculate the maximum possible side length, and finally return `maxSide * maxSide`.

### Complexity

*   **Time Complexity:** `O(N^2)`, where `N` is the number of rectangles. Since `N` is up to 1000, `N^2` is roughly `10^6`, which easily fits within time limits.
*   **Space Complexity:** `O(1)` (excluding input/output).
