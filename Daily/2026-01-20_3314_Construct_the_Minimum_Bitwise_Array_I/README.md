# 3314. Construct the Minimum Bitwise Array I

**Difficulty:** Easy  
**Topics:** Bit Manipulation, Array  
**Date:** 2026-01-20

## Problem Description

You are given an array `nums` consisting of `n` prime integers.

You need to construct an array `ans` of length `n`, such that, for each index `i`, the bitwise OR of `ans[i]` and `ans[i] + 1` is equal to `nums[i]`, i.e., `ans[i] OR (ans[i] + 1) == nums[i]`.

Additionally, you must minimize each value of `ans[i]` in the resulting array.

If it is not possible to find such a value for `ans[i]` that satisfies the condition, then set `ans[i] = -1`.

## Example 1

**Input:** `nums = [2,3,5,7]`  
**Output:** `[-1,1,4,3]`  
**Explanation:**  
*   For `i = 0`, no `ans[0]` satisfies `ans[0] OR (ans[0] + 1) = 2`, so `ans[0] = -1`.
*   For `i = 1`, `1 OR (1 + 1) = 1 OR 2 = 3`. Smallest is 1.
*   For `i = 2`, `4 OR (4 + 1) = 4 OR 5 = 5`. Smallest is 4.
*   For `i = 3`, `3 OR (3 + 1) = 3 OR 4 = 7`. Smallest is 3.

## Example 2

**Input:** `nums = [11,13,31]`  
**Output:** `[9,12,15]`  
**Explanation:**  
*   For `11` (1011): `9` (1001). `9 OR 10` = `1001 OR 1010` = `1011` (11).
*   For `13` (1101): `12` (1100). `12 OR 13` = `1100 OR 1101` = `1101` (13).
*   For `31` (11111): `15` (01111). `15 OR 16` = `01111 OR 10000` = `11111` (31).

## Constraints

*   `1 <= nums.length <= 100`
*   `2 <= nums[i] <= 1000`
*   `nums[i]` is a prime number.

## Solution Explanation

We need to solve `x | (x + 1) = n` for the smallest `x`.

### Observation
The operation `x | (x + 1)` essentially fills the consecutive run of suffix ones in `x` from the right.
Specifically, if `x` ends in binary `...011...1` (k ones), then `x + 1` ends in `...100...0` (k zeros).
Depending on the carry propagation, `x | (x + 1)` turns the least significant zero bit of `x` into a `1`.
Wait, actually `x | (x + 1)` always results in a number ending with a run of ones.
*   If `x` ends in 0, `x+1` ends in 1. `x | (x+1)` matches `x` but last bit is 1.
*   If `x` ends in 01, `x+1` ends in 10. `x | (x+1)` matches `x` but last 2 bits are 11.
*   Thus, `n` must end with a sequence of `1`s. Since `n` is prime (and assuming >2), it is odd, so it always ends with at least one `1`.

### Finding Minimal x
To get `n`, `x` must be `n` but with one specific bit turned off.
Since `x | (x+1) = n` sets the "lowest zero bit of x" to 1, this means `n` is just `x` with that zero turned to one.
Therefore, `x` is `n` with a single bit `1` turned to `0`.
For `x | (x+1)` to be precisely `n`, `x` must be formed by taking `n` and flipping the **most significant bit** of the contiguous block of trailing 1s to 0.

Example: `n = 23` (`10111`)
Trailing 1s: `111` (3 bits).
Flip the MSB of `111` (which is bit 2, value 4).
`x = 10011` (`19`).
Check: `19 + 1 = 20` (`10100`). `19 | 20` = `10011 | 10100` = `10111` (`23`).

### Algorithm
1.  **Check Even:** If `n` is even (e.g., 2), return -1 (since `n` must end in 1).
2.  **Identify MSB of Trailing Ones:**
    *   One trick to isolate the run of trailing ones is `(n + 1) & ~n`.
    *   Let `n = ...0111`. `n+1 = ...1000`. `~n = ...1000` (in lower bits).
    *   `(n+1) & ~n` gives the bit *just above* the trailing ones (the carry position).
    *   Shift right by 1 to get the actual MSB of the trailing ones.
3.  **Construct x:** `x = n & ~(identified_bit)`.

This `O(1)` per number approach works perfectly.
