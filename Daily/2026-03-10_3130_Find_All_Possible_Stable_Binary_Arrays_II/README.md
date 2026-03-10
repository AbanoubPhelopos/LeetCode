# 3130. Find All Possible Stable Binary Arrays II

**Difficulty:** Hard  
**Topics:** Dynamic Programming, Prefix Sum  
**Date:** 2026-03-10

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
The two possible stable binary arrays are [1,0] and [0,1].
```

**Example 2:**
```
Input: zero = 1, one = 2, limit = 1
Output: 1
Explanation:
The only possible stable binary array is [1,0,1].
```

**Example 3:**
```
Input: zero = 3, one = 3, limit = 2
Output: 14
Explanation:
All the possible stable binary arrays are [0,0,1,0,1,1], [0,0,1,1,0,1], [0,1,0,0,1,1], [0,1,0,1,0,1], [0,1,0,1,1,0], [0,1,1,0,0,1], [0,1,1,0,1,0], [1,0,0,1,0,1], [1,0,0,1,1,0], [1,0,1,0,0,1], [1,0,1,0,1,0], [1,0,1,1,0,0], [1,1,0,0,1,0], and [1,1,0,1,0,0].
```

## Constraints

*   `1 <= zero, one, limit <= 1000`

## Solution Approach

This problem is an extension of **3129. Find All Possible Stable Binary Arrays I**, but with constraints up to $1000$ instead of $200$. While the combinatorial approach ($O(\text{limit} \times \min(\text{zero}, \text{one}))$) works well, there is also a very efficient Dynamic Programming approach that perfectly handles $1000 \times 1000$ constraints in $O(\text{zero} \times \text{one})$ time by optimizing transitions.

We define state `dp[i][j][k]`:
*   `i` is the number of `0`s remaining to be placed.
*   `j` is the number of `1`s remaining to be placed.
*   `k` is $0$ if the array ends with a `0`, and $1$ if it ends with a `1`.

The value represents the number of valid stable arrangements of length $i + j$.

### Base Cases
Before looking at transitions, we initialize the pure sequences (no mixing). 
If we put down $i \le \text{limit}$ zeroes, there's exactly $1$ way to do this if we end in $0$: `dp[i][0][0] = 1`.
If we put down $j \le \text{limit}$ ones, there's exactly $1$ way to do this if we end in $1$: `dp[0][j][1] = 1`.

### Transitions
Consider `dp[i][j][0]`. We want to append a `0`. This `0` can be appended to any valid sequence of length $i+j-1$ that ended in either `0` or `1`, except for sequences that already have `limit` contiguous `0`s at the end.
So we start with `dp[i-1][j][0] + dp[i-1][j][1]`.
However, this might include invalid sequences ending with `limit + 1` continuous `0`s. We must subtract out exactly the cases where exactly `limit` zeroes were placed right *after* a sequence ending in `1`.
When we subtract the over-counted arrays, we look exactly `limit + 1` steps back for zeroes: `dp[i - limit - 1][j][1]`.

So the transition becomes:
```
dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1]
if (i > limit):
    dp[i][j][0] -= dp[i - limit - 1][j][1]
```

Similarly for ending in `1`:
```
dp[i][j][1] = dp[i][j-1][0] + dp[i][j-1][1]
if (j > limit):
    dp[i][j][1] -= dp[i][j - limit - 1][0]
```

### Complexity
By maintaining the running sum implicitly and explicitly subtracting the exact boundary violation, we reduce what would normally be an $O(\text{limit})$ transition loop down to $O(1)$.
*   **Time Complexity:** $O(\text{zero} \times \text{one})$. For limits up to 1000, $1000 \times 1000 = 10^6$ operations, which takes practically no time.
*   **Space Complexity:** $O(\text{zero} \times \text{one})$ to store the `dp` table.
