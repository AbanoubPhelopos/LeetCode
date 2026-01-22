# 1925. Count Square Sum Triples

**Difficulty:** Easy  
**Topics:** Math, Enumeration  
**Date:** 2025-12-08

## Problem Description

A **square triple** `(a, b, c)` is a triple where `a`, `b`, and `c` are integers and `a² + b² = c²`.

Given an integer `n`, return the number of square triples such that `1 <= a, b, c <= n`.

## Example 1

**Input:** `n = 5`  
**Output:** `2`  
**Explanation:** The square triples are `(3,4,5)` and `(4,3,5)`.

## Example 2

**Input:** `n = 10`  
**Output:** `4`  
**Explanation:** The square triples are `(3,4,5)`, `(4,3,5)`, `(6,8,10)`, and `(8,6,10)`.

## Constraints

*   `1 <= n <= 250`

## Solution Explanation

We need to find all Pythagorean triples `(a, b, c)` where `a² + b² = c²` and `1 <= a, b, c <= n`.

### Approach: Brute Force Enumeration

Given the small constraint (`n <= 250`), we can enumerate all possible pairs `(a, b)`.

1.  For each pair `(i, j)` where `3 <= i, j <= n` (since smallest Pythagorean triple is 3,4,5):
    *   Compute `c = i² + j²`.
    *   If `c > n²`, break (optimization).
    *   Check if `c` is a perfect square by computing `sqrt(c)` and verifying `temp * temp == c`.
    *   If valid, increment answer.

Note: `(a, b)` and `(b, a)` are counted separately since order matters.

### Complexity
*   **Time Complexity:** `O(N²)`.
*   **Space Complexity:** `O(1)`.
