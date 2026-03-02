# 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers

**Difficulty:** Medium  
**Topics:** String, Greedy  
**Date:** 2026-03-01

## Problem Description

A decimal number is called **deci-binary** if each of its digits is either `0` or `1` without any leading zeros. For example, `101` and `1100` are deci-binary, while `112` and `3001` are not.

Given a string `n` that represents a positive decimal integer, return the **minimum** number of positive **deci-binary** numbers needed so that they sum up to `n`.

**Example 1:**
```
Input: n = "32"
Output: 3
Explanation: 10 + 11 + 11 = 32
```

**Example 2:**
```
Input: n = "82734"
Output: 8
```

**Example 3:**
```
Input: n = "27346209830709182346"
Output: 9
```

## Constraints

*   `1 <= n.length <= 10^5`
*   `n` consists of only digits.
*   `n` does not contain any leading zeros and represents a positive integer.

## Solution Approach

The problem asks for the minimum number of deci-binary numbers needed to sum up to `n`. A deci-binary number is composed solely of the digits `0` and `1`. This means that each deci-binary number can contribute at most `1` to any single digit position of the sum.

Because of this, if a specific digit in `n` is `x`, we will need exactly `x` deci-binary numbers that have a `1` at that position to sum up to `x`. 

To minimize the total number of deci-binary numbers used, we simply need to find the **maximum digit** present in the string `n`. 

If the maximum digit is `m`, we must have at least `m` deci-binary numbers. We can construct exactly `m` such numbers to satisfy all digits by putting a `1` in the first `x` numbers (where `x` is the value of the digit at a specific position in `n`) and `0` in the remaining `m - x` numbers for that position.

Therefore, the answer is just the numerical value of the largest digit character in the string `n`.
