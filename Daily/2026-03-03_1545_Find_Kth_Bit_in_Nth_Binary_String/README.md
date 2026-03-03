# 1545. Find Kth Bit in Nth Binary String

**Difficulty:** Medium  
**Topics:** String, Recursion  
**Date:** 2026-03-03

## Problem Description

Given two positive integers `n` and `k`, the binary string `Sn` is formed as follows:

*   `S1 = "0"`
*   `Si = Si - 1 + "1" + reverse(invert(Si - 1))` for `i > 1`

Where `+` denotes the concatenation operation, `reverse(x)` returns the reversed string `x`, and `invert(x)` inverts all the bits in `x` (0 changes to 1 and 1 changes to 0).

For example, the first four strings in the above sequence are:

*   `S1 = "0"`
*   `S2 = "011"`
*   `S3 = "0111001"`
*   `S4 = "011100110110001"`

Return the `kth` bit in `Sn`. It is guaranteed that `k` is valid for the given `n`.

**Example 1:**
```
Input: n = 3, k = 1
Output: "0"
Explanation: S3 is "0111001".
The 1st bit is "0".
```

**Example 2:**
```
Input: n = 4, k = 11
Output: "1"
Explanation: S4 is "011100110110001".
The 11th bit is "1".
```

## Constraints

*   `1 <= n <= 20`
*   `1 <= k <= 2^n - 1`

## Solution Approach

The problem states that string `Sn` is constructed recursively from `Sn-1`. Given `1 <= n <= 20`, building the full string up to $O(2^n)$ in length is possible (around 1 million characters), but we can find the $k$-th bit much more efficiently without building the string at all using recursion and a divide-and-conquer strategy.

The string `Sn` has length $2^n - 1$.
The construction `Sn = Sn-1 + "1" + reverse(invert(Sn-1))` implies that the string is divided into three parts:
1.  **Left Part:** The first half of `Sn` is exactly `Sn-1`. It has length $2^{n-1} - 1$.
2.  **Middle Bit:** The middle bit of `Sn` is always `'1'`. It is at index $mid = 2^{n-1}$.
3.  **Right Part:** The second half of `Sn` is `reverse(invert(Sn-1))`. It also has length $2^{n-1} - 1$.

Let `len` be the length of `Sn`, so $len = 2^n - 1$. The middle index $mid$ is $(len + 1) / 2 = 2^{n-1}$.

When looking for the $k$-th bit (1-indexed), there are three cases:
1.  **k == mid:** The requested bit is exactly in the middle. We immediately know the answer is `'1'`.
2.  **k < mid:** The requested bit lies in the first half of `Sn`. Since the first half is exactly `Sn-1`, the answer is the same as finding the $k$-th bit in `Sn-1`. We recurse: `findKthBit(n - 1, k)`.
3.  **k > mid:** The requested bit lies in the second half of `Sn`. The second half is the reverse and inverse of `Sn-1`. 
    *   Since it's reversed, the $k$-th bit of `Sn` corresponds to the $(len - k + 1)$-th bit of `Sn-1`.
    *   Since it's inverted, we must flip the bit returned from `Sn-1`.
    *   Thus, we recurse to find the bit in `Sn-1` at index `len - k + 1`, and return its inverse (if it is `'0'` return `'1'`, else return `'0'`).

**Base Case:** 
If `n == 1`, `S1` is just `"0"`, and `k` must be 1. We just return `'0'`.

This recursive approach cuts the search space in half at each step. Thus, its time complexity is $O(n)$, which is at most 20 operations, making it extremely efficient. The space complexity is also $O(n)$ due to the recursion stack.
