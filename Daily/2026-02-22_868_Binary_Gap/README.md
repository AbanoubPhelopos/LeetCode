# 868. Binary Gap

**Difficulty:** Easy  
**Topics:** Bit Manipulation  
**Date:** 2026-02-22

## Problem Description

Given a positive integer `n`, find and return the **longest distance** between any two adjacent `1`'s in the binary representation of `n`. If there are no two adjacent `1`'s, return `0`.

Two `1`'s are adjacent if there are only `0`'s separating them (possibly no `0`'s). The distance between two `1`'s is the absolute difference between their bit positions. For example, the two `1`'s in `"1001"` have a distance of 3.

**Example 1:**
```
Input: n = 22
Output: 2
Explanation: 22 in binary is "10110".
The first adjacent pair of 1's is "10110" with a distance of 2.
The second adjacent pair of 1's is "10110" with a distance of 1.
The answer is the largest of these two distances, which is 2.
Note that "10110" is not a valid pair since there is a 1 separating the two 1's underlined.
```

**Example 2:**
```
Input: n = 8
Output: 0
Explanation: 8 in binary is "1000".
There are not any adjacent pairs of 1's in the binary representation of 8, so we return 0.
```

**Example 3:**
```
Input: n = 5
Output: 2
Explanation: 5 in binary is "101".
```

## Constraints

*   `1 <= n <= 10^9`

## Solution Approach

The objective is to find the maximum distance between adjacent `1`s in the binary representation of `n`. We can iterate through the bits of `n` from the least significant bit (LSB) to the most significant bit (MSB).

We can do this by repeatedly checking the last bit (`n % 2` or `n & 1`) and then shifting `n` to the right (`n /= 2` or `n >>= 1`).

While doing so, we maintain the following state:
-   `found_first_one`: A boolean flag indicating if we have encountered at least one `1` so far. We only start counting distances *after* the first `1`.
-   `curr`: An integer simulating the counter since the last seen `1`. It starts counting distance. When we hit a new `1`, `curr` represents the distance from the previous `1` to the current `1`.
-   `maxd`: The maximum distance found so far.

Algorithm steps:
1.  Initialize `maxd = 0`, `curr = 0`, `found_first_one = false`.
2.  Loop while `n > 0`:
    *   Extract the current bit: `bit = n % 2`.
    *   If `bit == 1`:
        *   If we had already found a previous `1` (`found_first_one` is true), the distance from that previous `1` to this new `1` is `curr`. We update `maxd = max(maxd, curr)`.
        *   Reset `curr = 1` because the next bit will be at a distance of 1 from this newly found `1`.
        *   Set `found_first_one = true`.
    *   If `bit == 0`:
        *   If we have already found a `1`, this `0` adds to the distance from the last seen `1`, so we increment `curr++`. If we haven't seen a `1` yet (i.e., we are parsing trailing zeros), we just ignore it.
    *   Divide `n` by 2 to move to the next bit.
3.  Return `maxd`.
