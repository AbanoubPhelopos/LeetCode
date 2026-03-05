# 693. Binary Number with Alternating Bits

**Difficulty:** Easy  
**Topics:** Bit Manipulation  
**Date:** 2026-02-18

## Problem Description

Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

**Example 1:**
```
Input: n = 5
Output: true
Explanation: The binary representation of 5 is: 101
```

**Example 2:**
```
Input: n = 7
Output: false
Explanation: The binary representation of 7 is: 111.
```

**Example 3:**
```
Input: n = 11
Output: false
Explanation: The binary representation of 11 is: 1011.
```

## Constraints

*   `1 <= n <= 2^31 - 1`

## Solution Approach

The objective is to verify if the binary representation of `n` strictly alternates between `0` and `1` (e.g., `10101` or `101010...`).

A clever and highly optimized way to check this without iterating through the bits one-by-one is to use bitwise operations.

1.  **Bitwise XOR (`^`) and Right Shift (`>>`):**
    If we shift `n` to the right by 1 bit (`n >> 1`), we align the adjacent bits of `n` together.
    If `n` has alternating bits (e.g., `n = 10101_2`), then `n >> 1 = 01010_2`.
    Notice that for every position where `n` has a `1`, `n >> 1` will have a `0`, and vice versa (up to the most significant bit).
    When we XOR them together (`x = n ^ (n >> 1)`), the result will be a binary number consisting *entirely* of `1`s from the least significant bit up to the original most significant bit.
    For example:
    `n = 5` (`101` in binary)
    `n >> 1 = 2` (`010` in binary)
    `x = 5 ^ 2 = 7` (`111` in binary)

    If `n` does *not* have alternating bits (e.g., `n = 11_2` = 3), then there is at least one adjacent pair of the same bits.
    `n = 3` (`...011` in binary)
    `n >> 1 = 1` (`...001` in binary)
    `x = 3 ^ 1 = 2` (`...010` in binary) - not all `1`s.

2.  **Checking if a number is `2^k - 1` (all ones):**
    To verify if `x` is in the form of `11...11` (all ones), we only need to add 1 to it (`x + 1`). This operation will cause a ripple carry that changes all the trailing `1`s to `0`s and turns the leading `0` into a `1`.
    For example, if `x = 7` (`...0111_2`), then `x + 1 = 8` (`...1000_2`).
    Notice that `x` and `x + 1` share absolutely no set bits. Thus, `x & (x + 1)` must exactly equal `0`.
    Therefore, the condition `(x & (x + 1)) == 0` is true if and only if `x` consists of a continuous block of `1`s starting from the least significant bit.

In C++, we must be careful with integer overflow when adding 1 to `x` if `n` happens to be near `2^31 - 1`. Specifically, if `n` is `101...01_2` matching the largest possible integer alternating pattern, `x = n ^ (n >> 1)` could be `2^31 - 1`, and `x + 1` could overflow a signed 32-bit integer. We use `unsigned int` for `x` to prevent this undefined behavior.

This approach takes $O(1)$ time complexity and $O(1)$ space complexity, evaluating the properties entirely via arithmetic and bitwise logic.
