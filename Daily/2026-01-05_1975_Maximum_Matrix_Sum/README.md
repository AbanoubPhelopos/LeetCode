# 1975. Maximum Matrix Sum

**Difficulty:** Medium  
**Topics:** Greedy, Array, Matrix  
**Date:** 2026-01-05

## Problem Description

You are given an `n x n` integer `matrix`. You can do the following operation any number of times:

*   Choose any two adjacent elements of `matrix` and multiply each of them by `-1`.

Two elements are considered adjacent if and only if they share a border.

Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.

## Example 1

**Input:** `matrix = [[1,-1],[-1,1]]`  
**Output:** `4`  
**Explanation:**  
We can follow the following steps to reach sum equals 4:  
1. Multiply the 2 elements in the first row by -1.  
2. Multiply the 2 elements in the first column by -1.

## Example 2

**Input:** `matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]`  
**Output:** `16`  
**Explanation:**  
We can follow the following step to reach sum equals 16:  
1. Multiply the 2 last elements in the second row by -1.

## Constraints

*   `n == matrix.length == matrix[i].length`
*   `2 <= n <= 250`
*   `-10^5 <= matrix[i][j] <= 10^5`

## Solution Explanation

The core operation allows us to multiply two adjacent cells by `-1`. This essentially allows us to move "negative signs" around the grid.
*   If we have two negative numbers adjacent to each other, apply the operation to make both positive.
*   If we have one negative number and one positive number adjacent, the negative sign "moves" to the neighbor.
*   We can use this property to move a negative sign to any position in the matrix.
*   If we have two separated negative numbers, we can move one towards the other until they are adjacent, and then eliminate both.

### Logic
1.  **Count Negatives:** Count the total number of negative integers in the matrix.
2.  **Total Absolute Sum:** Calculate the sum of absolute values of all elements.
3.  **Minimum Absolute Value:** Keep track of the minimum absolute value (`minAbs`) across the whole matrix.
4.  **Result:**
    *   If the count of negative numbers is **even**, we can pair them all up and flip them to positive. The answer is simply `sum(abs(all))`.
    *   If the count of negative numbers is **odd**, we will always be left with exactly one negative number. To maximize the total sum, we should ensure this negative sign ends up on the element with the smallest absolute value.
    *   The answer is `sum(abs(all)) - 2 * minAbs`.
        *   Why `2 *`? Because `sum` already included `+minAbs`. Subtracting `minAbs` once removes it from the sum (making it 0). Subtracting it again effectively makes it `-minAbs`.

This Greedy approach ensures optimal result.
