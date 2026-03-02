# 1404. Number of Steps to Reduce a Number in Binary Representation to One

**Difficulty:** Medium  
**Topics:** String, Bit Manipulation  
**Date:** 2026-02-26

## Problem Description

Given the binary representation of an integer as a string `s`, return the number of steps to reduce it to `1` under the following rules:

*   If the current number is even, you have to divide it by `2`.
*   If the current number is odd, you have to add `1` to it.

It is guaranteed that you can always reach one for all test cases.

**Example 1:**
```
Input: s = "1101"
Output: 6
Explanation: "1101" corressponds to number 13 in their decimal representation.
Step 1) 13 is odd, add 1 and obtain 14. 
Step 2) 14 is even, divide by 2 and obtain 7.
Step 3) 7 is odd, add 1 and obtain 8.
Step 4) 8 is even, divide by 2 and obtain 4.  
Step 5) 4 is even, divide by 2 and obtain 2. 
Step 6) 2 is even, divide by 2 and obtain 1.  
```

**Example 2:**
```
Input: s = "10"
Output: 1
Explanation: "10" corresponds to number 2 in their decimal representation.
Step 1) 2 is even, divide by 2 and obtain 1.  
```

**Example 3:**
```
Input: s = "1"
Output: 0
```

## Constraints

*   `1 <= s.length <= 500`
*   `s` consists of characters `'0'` or `'1'`
*   `s[0] == '1'`

## Solution Approach

The problem requires us to simulate the process of dividing by 2 (if even) or adding 1 (if odd) until the number becomes `1`. Operating directly on the string is much more efficient than converting the potentially very large string to an integer.

We process the string from right to left (from the least significant bit to the most significant bit), maintaining a `carry` to handle the addition of 1.
We loop from index `s.size() - 1` down to `1` (we stop at `0` because when we reach the first bit, we must consider if there is still a carry).

In each iteration, the current effective bit is `(s[i] - '0') + carry`.
*   If `bit == 1`: This means the current number is odd. We must add 1. Adding 1 to this least significant bit `1` makes it `0` and generates a carry of `1`. Then, the number becomes even, so we must divide by 2 (which is effectively shifting right by one or moving to the next bit). The addition step and the division step combined take **2 steps**. Our new `carry` is `1`.
*   If `bit == 0` (or `2`, which modulo 2 is `0`): This means the current number is even. We just divide by 2. This takes **1 step**. If `bit` was `2` (which happens when `s[i] == '1'` and `carry == 1`), the carry remains `1` for the next position. If `bit` was `0`, the `carry` remains `0`.

After the loop, we are at the most significant bit `s[0]` which is always `'1'`. If we have a `carry == 1`, it means adding 1 propagated all the way to the front, and the most significant bit together with the carry makes `1 + 1 = 2` (binary `10`). We need exactly 1 more step (divide by 2) to reduce it to `1`. Thus, we add `carry` to the total `steps`.
