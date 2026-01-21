# 3315. Construct the Minimum Bitwise Array II

**Difficulty:** Medium  
**Topics:** Bit Manipulation, Array  
**Date:** 2026-01-21

## Problem Description

You are given an array `nums` consisting of `n` prime integers.

You need to construct an array `ans` of length `n`, such that, for each index `i`, the bitwise OR of `ans[i]` and `ans[i] + 1` is equal to `nums[i]`, i.e., `ans[i] OR (ans[i] + 1) == nums[i]`.

Additionally, you must minimize each value of `ans[i]` in the resulting array.

If it is not possible to find such a value for `ans[i]` that satisfies the condition, then set `ans[i] = -1`.

## Example 1

**Input:** `nums = [2,3,5,7]`  
**Output:** `[-1,1,4,3]`

## Example 2

**Input:** `nums = [11,13,31]`  
**Output:** `[9,12,15]`

## Constraints

*   `1 <= nums.length <= 100`
*   `2 <= nums[i] <= 10^9`
*   `nums[i]` is a prime number.

## Solution Explanation

This problem is nearly identical to LeetCode 3314, but with larger constraints (`nums[i]` up to `10^9`). The logic remains the same: find `x` such that `x | (x + 1) == n`.

### Key Insight
`x | (x+1)` sets the lowest `0` bit of `x` to `1`. Therefore, `n = x | (x+1)` must end with a sequence of trailing `1`s. If `n` is even (ends with `0`), it's impossible, so return `-1`.

For odd `n`, the answer `x` is `n` with the highest bit of its trailing-ones block flipped to `0`.

### Algorithm (C++20)
1.  **Count Trailing Ones:** Use `std::countr_one((unsigned)p)` from `<bit>` to count trailing `1`s in `p`.
2.  **Identify Bit to Flip:** The bit to flip is at position `(trailing_ones - 1)`. So `remB = (1 << countr_one(p)) >> 1`.
    *   If `p` is even (like `2`), `countr_one(p)` is `0`, so `remB = (1 << 0) >> 1 = 0`.
3.  **Handle Impossible Case:** If `remB == 0`, it means `p` is even, and we need to set result to `-1`. The expression `-(remB==0) & ~p` handles this: if `remB` is 0, `-(remB==0)` is `-1` (all bits set), and `~p` XORed with `p` gives `-1`. Otherwise, it's `0`.
4.  **Construct Answer:** `p ^= remB | (-(remB==0) & ~p)`.

This is an `O(1)` per element solution using C++20 bit utilities.
