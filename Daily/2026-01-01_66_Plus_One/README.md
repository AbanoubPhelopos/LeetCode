# 66. Plus One

**Difficulty:** Easy  
**Topics:** Array, Math  
**Date:** 2026-01-01

## Problem Description

You are given a large integer represented as an integer array `digits`, where each `digits[i]` is the `ith` digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading `0`'s.

Increment the large integer by one and return the resulting array of digits.

## Example 1

**Input:** `digits = [1,2,3]`  
**Output:** `[1,2,4]`  
**Explanation:** The array represents the integer 123.  
Incrementing by one gives 123 + 1 = 124.  
Thus, the result should be `[1,2,4]`.

## Example 2

**Input:** `digits = [4,3,2,1]`  
**Output:** `[4,3,2,2]`  
**Explanation:** The array represents the integer 4321.  
Incrementing by one gives 4321 + 1 = 4322.  
Thus, the result should be `[4,3,2,2]`.

## Example 3

**Input:** `digits = [9]`  
**Output:** `[1,0]`  
**Explanation:** The array represents the integer 9.  
Incrementing by one gives 9 + 1 = 10.  
Thus, the result should be `[1,0]`.

## Constraints

*   `1 <= digits.length <= 100`
*   `0 <= digits[i] <= 9`
*   `digits` does not contain any leading `0`'s.

## Solution Explanation

We need to add 1 to the number represented by the array. This mimics the standard addition process taught in school.

### Approach

1.  **Iterate Backwards:** Start from the last digit (least significant).
2.  **Add Carry:** Add the carry (initially 1) to the current digit.
3.  **Update Digit:**
    *   If `digit + carry < 10`, then `digit` becomes `digit + carry`, and `carry` becomes 0. We can stop here because no further digits will be affected.
    *   If `digit + carry == 10`, then `digit` becomes 0, and `carry` remains 1. We continue to the next digit to the left.
4.  **Handle Overflow:** If we finish the loop and `carry` is still 1 (e.g., input was `[9, 9]`), it means the number increased in length (e.g., `100`). We prepend `1` to the array.

This approach runs in **O(n)** time, where n is the number of digits.
