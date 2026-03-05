# 190. Reverse Bits

**Difficulty:** Easy  
**Topics:** Divide and Conquer, Bit Manipulation  
**Date:** 2026-02-16

## Problem Description

Reverse bits of a given 32 bits signed integer.

**Example 1:**
```
Input: n = 43261596
Output: 964176192
Explanation:
Integer    Binary
43261596   00000010100101000001111010011100
964176192  00111001011110000010100101000000
```

**Example 2:**
```
Input: n = 2147483644
Output: 1073741822
Explanation:
Integer    Binary
2147483644 01111111111111111111111111111100
1073741822 00111111111111111111111111111110
```

## Constraints

*   `0 <= n <= 2^31 - 2`
*   `n` is even.

## Follow up:
If this function is called many times, how would you optimize it?

## Solution Approach

The problem asks us to reverse the 32 bits of an unsigned integer. A very elegant way to achieve this without processing bit-by-bit linearly is to use a Divide and Conquer approach.

The idea is to recursively split the sequence of bits in half, reverse the corresponding halves, and then combine them in reversed order.
For example, if we have a string of length 4 `abcd`, we split it into `ab` and `cd`. We reverse `lo` and `hi` subparts independently. The inverted combination becomes `reverse(cd) + reverse(ab)`.

1.  **Base Case:** If the length of the bit sequence to reverse is 1, it's just a single bit. We return that bit (`v & 1u`).
2.  **Divide Phase:** For a sequence of length `len`, we calculate the midpoint `half = len >> 1`. 
    *   We create a mask to extract the lower `half` bits: `mask = (1u << half) - 1u`.
    *   The lower half is `lo = v & mask`.
    *   The upper half is `hi = v >> half`.
3.  **Conquer and Combine:** We recursively reverse both `lo` and `hi`. Since `lo` originally occupied the bottom `half` bits and `hi` occupied the top `half` bits, their reversed versions must swap positions. We shift the reversed `lo` left by `half` bits and bitwise OR it with the reversed `hi`.

The given solution effectively performs this recursive split:
```cpp
uint32_t rev(uint32_t v, int len) {
    if (len == 1) return v & 1u;

    int half = len >> 1;
    uint32_t mask = (1u << half) - 1u;
    uint32_t lo = v & mask;
    uint32_t hi = v >> half;

    return (rev(lo, half) << half) | rev(hi, half);
}
```

Since the depth of the recursion tree is $\log_2(32) = 5$, and at each level $k$ we do $2^k$ constant time operations, the overall time complexity is $O(\log(\text{bits}))$, making it extremely fast.

### Optimization for multiple calls (Follow up)
If the function is called frequently, instead of recursion, one can use an iterative bit-masking technique to swap adjacent bits, then adjacent 2-bit blocks, then 4-bit blocks, 8-bit blocks, and finally 16-bit blocks. Alternatively, breaking the 32-bit integer into four 8-bit bytes and using an array-based lookup table (cache) of size 256 that maps every byte to its reversed equivalent can yield an $O(1)$ constant time execution without deep bitwise arithmetic per call.
