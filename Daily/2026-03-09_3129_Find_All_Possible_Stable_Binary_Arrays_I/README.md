# 3129. Find All Possible Stable Binary Arrays I

**Difficulty:** Medium  
**Topics:** Dynamic Programming, Combinatorics, Prefix Sum  
**Date:** 2026-03-09

## Problem Description

You are given 3 positive integers `zero`, `one`, and `limit`.

A binary array `arr` is called stable if:

*   The number of occurrences of `0` in `arr` is exactly `zero`.
*   The number of occurrences of `1` in `arr` is exactly `one`.
*   Each subarray of `arr` with a size greater than `limit` must contain both `0` and `1`.

Return the total number of stable binary arrays.

Since the answer may be very large, return it modulo $10^9 + 7$.

**Example 1:**
```
Input: zero = 1, one = 1, limit = 2
Output: 2
Explanation:
The two possible stable binary arrays are [1,0] and [0,1], as both arrays have a single 0 and a single 1, and no subarray has a length greater than 2.
```

**Example 2:**
```
Input: zero = 1, one = 2, limit = 1
Output: 1
Explanation:
The only possible stable binary array is [1,0,1].
Note that the binary arrays [1,1,0] and [0,1,1] have subarrays of length 2 with identical elements, hence, they are not stable.
```

**Example 3:**
```
Input: zero = 3, one = 3, limit = 2
Output: 14
Explanation:
All the possible stable binary arrays are [0,0,1,0,1,1], [0,0,1,1,0,1], [0,1,0,0,1,1], [0,1,0,1,0,1], [0,1,0,1,1,0], [0,1,1,0,0,1], [0,1,1,0,1,0], [1,0,0,1,0,1], [1,0,0,1,1,0], [1,0,1,0,0,1], [1,0,1,0,1,0], [1,0,1,1,0,0], [1,1,0,0,1,0], and [1,1,0,1,0,0].
```

## Constraints

*   `1 <= zero, one, limit <= 200`

## Solution Approach

This problem can be solved gracefully using combinatorics and the Inclusion-Exclusion Principle (or stars and bars with an upper bound capacity). Since no subarray of length greater than `limit` can have only `0`s or only `1`s, it specifically means that there can be no contiguous block of `0`s longer than `limit`, and no contiguous block of `1`s longer than `limit`.

The structure of the array is essentially alternating blocks of `0`s and blocks of `1`s.
Let's suppose there are $k$ blocks of `0`s. Since the blocks of `0`s and `1`s must alternate, the number of blocks of `1`s can only be:
- $k - 1$ (starts and ends with a block of `0`)
- $k$ (starts with `0`, ends with `1`)
- $k$ (starts with `1`, ends with `0`)
- $k + 1$ (starts and ends with a block of `1`)

For a given number of items $N$ (e.g., total zeros) placing them into $K$ non-empty groups such that no group exceeds capacity $L$ (which is our `limit`) can be computed using a known combinatorial formula derived from stars and bars and inclusion-exclusion:
$$ F(N, K, L) = \sum_{j=0}^{\lfloor \frac{N-K}{L} \rfloor} (-1)^j \cdot \binom{K}{j} \cdot \binom{N - j \cdot L - 1}{K - 1} $$

The full algorithm proceeds as follows:
1.  Precompute factorials and inverse factorials up to `zero + one` to efficiently calculate permutations and combinations $\binom{n}{k}$ modulo $10^9 + 7$.
2.  Define the bounding counting function $F(N, K, L)$ as described above to distribute $N$ identical items into $K$ baskets with a capacity of $L$ items per basket.
3.  Iterate over the possible number of `0`-blocks, $k$. It can range from $1$ up to $\min(\text{zero}, \text{one} + 1)$.
    *   Compute the ways to arrange the `0`s into $k$ blocks: $f_z = F(\text{zero}, k, \text{limit})$.
    *   If $f_z == 0$, skip to the next $k$.
    *   The `1`s can be placed into $k-1$, $k$, $k$, or $k+1$ blocks. We calculate the sum of these possibilities: $f_o = F(\text{one}, k-1, \text{limit}) + 2 \times F(\text{one}, k, \text{limit}) + F(\text{one}, k+1, \text{limit})$.
    *   Multiply $f_z$ by $f_o$ and add it to our running total, applying modulo $10^9+7$ at every step.
    
This approach calculates the answer with theoretical bounds mathematically, performing significantly faster and using less memory compared to dynamic programming simulations.
