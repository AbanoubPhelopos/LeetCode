# 1980. Find Unique Binary String

**Difficulty:** Medium  
**Topics:** Array, Hash Table, Math, String, Backtracking  
**Date:** 2026-03-08

## Problem Description

Given an array of strings `nums` containing `n` unique binary strings each of length `n`, return a binary string of length `n` that does not appear in `nums`. If there are multiple answers, you may return any of them.

**Example 1:**
```
Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.
```

**Example 2:**
```
Input: nums = ["00","01"]
Output: "11"
Explanation: "11" does not appear in nums. "10" would also be correct.
```

**Example 3:**
```
Input: nums = ["111","011","001"]
Output: "101"
Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.
```

## Constraints

*   `n == nums.length`
*   `1 <= n <= 16`
*   `nums[i].length == n`
*   `nums[i]` is either `'0'` or `'1'`.
*   All the strings of `nums` are unique.

## Solution Approach

This problem is a classic application of **Cantor's Diagonalization Argument**. 

The input gives us `n` strings, each of length `n`. We need to construct a new string of length `n` that is guaranteed to be different from every string in the input list.

To do this, we can construct our result string character by character such that the $i$-th character of our result string is different from the $i$-th character of the $i$-th string in `nums`.

Let's break it down:
1.  Look at the 0th character of `nums[0]`. If it is `'0'`, set the 0th character of our result to `'1'`. If it is `'1'`, set the 0th character of our result to `'0'`. This guarantees our new string differs from `nums[0]` by at least the 0th character.
2.  Look at the 1st character of `nums[1]`. Flip it to determine the 1st character of our result. This guarantees our new string differs from `nums[1]` by at least the 1st character.
3.  Continue this for every index $i$ up to $n-1$.

Since our new string differs from `nums[i]` at index $i$ for every string in the list, it is mathematically guaranteed that our new string is completely unique and not present in `nums`.

Algorithm:
1. Initialize an empty string `result`.
2. Loop `i` from `0` to `n-1`.
3. Check `nums[i][i]`. 
4. If it's `'1'`, append `'0'` to `result`. Otherwise, append `'1'` to `result`.
5. Return the constructed `result`.

The time complexity is $O(n)$, as we iterate exactly $n$ times building a string of length $n$. The space complexity is $O(1)$ ignoring the string to be returned, making it highly optimal.
