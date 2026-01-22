# 3577. Count the Number of Computer Unlocking Permutations

**Difficulty:** Medium  
**Topics:** Array, Math, Combinatorics  
**Date:** 2025-12-10

## Problem Description

You are given an array `complexity` of length `n`. There are `n` locked computers labeled from `0` to `n-1`, each with its own unique password. The password for computer `i` has complexity `complexity[i]`.

The password for computer `0` is already decrypted (root). To decrypt computer `i`, you need a previously unlocked computer `j` where `j < i` and `complexity[j] < complexity[i]`.

Find the number of permutations of `[0, 1, 2, ..., (n-1)]` representing a valid order to unlock all computers, starting from computer `0`. Return the result modulo `10^9 + 7`.

## Example 1

**Input:** `complexity = [1,2,3]`  
**Output:** `2`  
**Explanation:** Valid permutations: `[0,1,2]` and `[0,2,1]`.

## Example 2

**Input:** `complexity = [3,3,3,4,4,4]`  
**Output:** `0`  
**Explanation:** No valid permutation exists.

## Constraints

*   `2 <= complexity.length <= 10^5`
*   `1 <= complexity[i] <= 10^9`

## Solution Explanation

Computer `0` must always be unlocked first (it's the root). For any other computer `i` to be unlockable, there must exist some `j < i` with `complexity[j] < complexity[i]`.

### Key Insight

Since computer `0` is the root, and we need `j < i` with `complexity[j] < complexity[i]`, the minimum complexity in positions `[0..i-1]` must be less than `complexity[i]`.

For all computers `1, 2, ..., n-1` to be unlockable, we need `complexity[0]` to be strictly less than all other complexities. Why? Because computer `0` is the only one we can unlock without a prerequisite, and it serves as the dependency for all others.

### Algorithm

1.  **Check Validity:** If any `complexity[i] <= complexity[0]` for `i > 0`, return 0.
2.  **Count Permutations:** If valid, computer `0` must be first. The remaining `n-1` computers can be unlocked in any order (since they all have `complexity > complexity[0]`, computer `0` can unlock any of them).
    *   Answer = `(n-1)!` = factorial of `(n-1)`.

### Complexity
*   **Time Complexity:** `O(N)`.
*   **Space Complexity:** `O(1)`.
