# 67. Add Binary

**Difficulty:** Easy  
**Topics:** Math, String, Bit Manipulation, Simulation  
**Date:** 2026-02-15

## Problem Description

Given two binary strings `a` and `b`, return their sum as a binary string.

**Example 1:**
```
Input: a = "11", b = "1"
Output: "100"
```

**Example 2:**
```
Input: a = "1010", b = "1011"
Output: "10101"
```

## Constraints

*   `1 <= a.length, b.length <= 10^4`
*   `a` and `b` consist only of `'0'` or `'1'` characters.
*   Each string does not contain leading zeros except for the zero itself.

## Solution Approach

The objective is to add two large binary numbers represented as strings. A straightforward full-adder simulation is suitable here.
To optimize the process, the provided approach uses `std::bitset`. Since the maximum length of either string is $10^4$, a `bitset<10001>` safely holds everything up to the maximum potential size.

1.  **Bitset Construction:**
    *   Initialize two bitsets `A` and `B` with strings `a` and `b`. The bitset automatically parses the rightmost character as the $0$-th index bit (LSB), the next as the $1$-st index bit, and so on. This handles string length discrepancies seamlessly.
    *   Determine the max possible length `M = max(a.length() + 1, b.length() + 1)`. The `+ 1` accounts for a potential overall carry bit.

2.  **Bitwise Addition:**
    *   Create a character array `C` of size `M + 1` to build the resulting string. `C[M] = '\0'` null-terminates it.
    *   Maintain a `carry` variable starting at `0`.
    *   Iterate `i` from `0` to `M - 1`:
        *   Calculate the sum for the current bit: `tmp = A[i] + B[i] + carry`.
        *   The bit to store is `tmp & 1` (equivalent to `tmp % 2`).
        *   Assign it to the appropriate (reversed) position in the character array `C`: `C[M - 1 - i] = '0' + (tmp & 1)`. We fill from the end of the array backwards because `i=0` is the LSB which goes at the end of the string.
        *   Calculate the new `carry` for the next position: `carry = tmp > 1` (equivalent to `tmp / 2`).

3.  **Formatting Output:**
    *   After the loop, the string is fully constructed in `C`. We just need to check if the most significant bit (at `C[0]`) is `'0'` (which happens if the final addition didn't over-flow a new bit). 
    *   If `C[0] == '0'`, we return the string starting from `C+1` to strip the leading zero. 
    *   Otherwise, we return the entire string `C`.

The time complexity is $O(\max(|a|, |b|))$ bounded by the max length, and space complexity is $O(\max(|a|, |b|))$ to hold the bitsets and character array representations.
