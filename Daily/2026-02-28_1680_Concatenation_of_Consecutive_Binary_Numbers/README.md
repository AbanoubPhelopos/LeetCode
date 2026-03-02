# 1680. Concatenation of Consecutive Binary Numbers

**Difficulty:** Medium  
**Topics:** Math, Bit Manipulation  
**Date:** 2026-02-28

## Problem Description

Given an integer `n`, return the decimal value of the binary string formed by concatenating the binary representations of `1` to `n` in order, modulo `10^9 + 7`.

**Example 1:**
```
Input: n = 1
Output: 1
Explanation: "1" in binary corresponds to the decimal value 1. 
```

**Example 2:**
```
Input: n = 3
Output: 27
Explanation: In binary, 1, 2, and 3 corresponds to "1", "10", and "11".
After concatenating them, we have "11011", which corresponds to the decimal value 27.
```

**Example 3:**
```
Input: n = 12
Output: 505379714
Explanation: The concatenation results in "1101110010111011110001001101010111100".
The decimal value of that is 118505380540.
After modulo 10^9 + 7, the result is 505379714.
```

## Constraints

*   `1 <= n <= 10^5`

## Solution Approach

The problem asks us to find the decimal value of the concatenation of binary representations from `1` to `n`. Let's build the resulting number iteratively.

When we append the binary representation of a number `i` to the current result string, it's equivalent to left-shifting the current result by the number of bits in `i`, and then adding `i` via bitwise OR.

For example, if our result is currently `1` (binary `1`) and we want to append `2` (binary `10` which has 2 bits):
1. Shift `1` left by 2 bits: `1 << 2` becomes `100` (binary) or `4` (decimal).
2. OR `2`: `100 | 10` becomes `110` (binary) or `6` (decimal).

How do we efficiently determine the number of bits in `i`?
We can notice that the number of bits increases exactly when `i` is a power of 2 (e.g., 1, 2, 4, 8...). 
A number `i` is a power of 2 if `(i & (i - 1)) == 0`.

Algorithm:
1. Initialize `res = 0` and `bits = 0`.
2. Iterate `i` from `1` to `n`.
   * Check if `i` is a power of 2 using `(i & (i - 1)) == 0`. If true, increment `bits`.
   * Left shift `res` by `bits` places.
   * Use bitwise OR to effectively append `i`: `res = ((res << bits) | i) % MOD`.
3. Return `res`.
