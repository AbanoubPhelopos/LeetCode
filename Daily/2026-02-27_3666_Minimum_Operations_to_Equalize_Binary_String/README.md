# 3666. Minimum Operations to Equalize Binary String

**Difficulty:** Hard  
**Topics:** String, Breadth-First Search, Queue  
**Date:** 2026-02-27

## Problem Description

You are given a binary string `s`, and an integer `k`.

In one operation, you must choose exactly `k` different indices and flip each `'0'` to `'1'` and each `'1'` to `'0'`.

Return the minimum number of operations required to make all characters in the string equal to `'1'`. If it is not possible, return `-1`.

**Example 1:**
```
Input: s = "110", k = 1
Output: 1
Explanation:
There is one '0' in s.
Since k = 1, we can flip it directly in one operation.
```

**Example 2:**
```
Input: s = "0101", k = 3
Output: 2
Explanation:
One optimal set of operations choosing k = 3 indices in each operation is:
Operation 1: Flip indices [0, 1, 3]. s changes from "0101" to "1000".
Operation 2: Flip indices [1, 2, 3]. s changes from "1000" to "1111".
Thus, the minimum number of operations is 2.
```

**Example 3:**
```
Input: s = "101", k = 2
Output: -1
Explanation:
Since k = 2 and s has only one '0', it is impossible to flip exactly k indices to make all '1'. Hence, the answer is -1.
```

## Constraints

*   `1 <= s.length <= 10^5`
*   `s[i]` is either `'0'` or `'1'`.
*   `1 <= k <= s.length`

## Solution Approach

The problem asks for the minimum number of operations to turn all elements into `'1'`s. We can model this as finding the shortest path in a state space where each state is defined by the **number of zeros** currently in the string. Due to symmetry, any two strings with the same number of zeros are reachable in the same minimum number of operations from the all-ones state (or vice-versa), assuming we only care about the count.

Let `n` be the length of the string and `z` be the current number of zeros. The number of ones is `ones = n - z`.
In one operation, we select `k` bits to flip. Suppose we choose to flip `x` zeros (which become ones) and `y` ones (which become zeros).
We must have:
*   `x + y = k` (we flip exactly `k` bits total)
*   `0 <= x <= z` (we can't flip more zeros than there are)
*   `0 <= y <= ones` (we can't flip more ones than there are) -> since `y = k - x`, this implies `k - ones <= x <= k`.

Thus, the possible values for `x` are exactly the integers in the range `[xMin, xMax]` where:
`xMin = max(0, k - ones) = max(0, k - n + z)`
`xMax = min(k, z)`

If `x` zeros are flipped to ones, and `y = k - x` ones are flipped to zeros, the new number of zeros `z'` will be:
`z' = (z - x) + y = z - x + k - x = z + k - 2x`

Notice that `z'` always has the same parity as `z + k`. For a given `z`, the possible next states `z'` form an arithmetic progression with a step of `-2` or `2` within the bounds `[z + k - 2 * xMax, z + k - 2 * xMin]`. They all share the same parity `(z + k) % 2`.

Since we are looking for the shortest path from the initial number of zeros `z0` to `0`, we can use Breadth-First Search (BFS). 
To avoid revisiting states and doing redundant work (which could lead to O(N^2) time complexity if we iterate over all possible `x` for every `z`), we can use two `set`s (one for each parity) containing all currently **unvisited** states. When we expand a state `z`, we query the appropriate set for unvisited states in the reachable range `[L, R]` and add them to our BFS queue, simultaneously removing them from the unvisited set.

This optimization ensures each possible state (0 to n) is added to the queue and processed at most once, and removing elements from the set takes O(1) amortized or O(log N) operations, leading to an overall O(N log N) time complexity.
