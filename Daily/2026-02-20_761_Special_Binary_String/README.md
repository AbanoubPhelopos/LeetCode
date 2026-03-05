# 761. Special Binary String

**Difficulty:** Hard  
**Topics:** String, Recursion  
**Date:** 2026-02-20

## Problem Description

Special binary strings are binary strings with the following two properties:

*   The number of `0`'s is equal to the number of `1`'s.
*   Every prefix of the binary string has at least as many `1`'s as `0`'s.

You are given a special binary string `s`.

A move consists of choosing two consecutive, non-empty, special substrings of `s`, and swapping them. Two strings are consecutive if the last character of the first string is exactly one index before the first character of the second string.

Return the lexicographically largest resulting string possible after applying the mentioned operations on the string.

**Example 1:**
```
Input: s = "11011000"
Output: "11100100"
Explanation: The strings "10" [occuring at s[1]] and "1100" [at s[3]] are swapped.
This is the lexicographically largest string possible after some number of swaps.
```

**Example 2:**
```
Input: s = "10"
Output: "10"
```

## Constraints

*   `1 <= s.length <= 50`
*   `s[i]` is either `'0'` or `'1'`.
*   `s` is a special binary string.

## Solution Approach

The definition of a "special binary string" is exactly the definition of a valid parentheses sequence, where `'1'` is an open parenthesis `(` and `'0'` is a closed parenthesis `)`.
The swap operation described is equivalent to swapping any two adjacent valid parenthesis sequences. Since we can swap any *adjacent* valid substrings, we can essentially use a bubble-sort-like procedure to reorder *all* sibling special substrings into any order we want.

To get the lexicographically largest string overall, we want the `'1'`s as early as possible. This means we should sort all sibling special substrings at the same nested level in lexicographically **descending** order.

Algorithm:
1.  **Identify Outer Components:** Scan the string `s` from left to right, maintaining a balance counter (`+1` for `'1'`, `-1` for `'0'`). Every time the balance drops to 0, we have identified a top-level valid "special" substring `s[i...j]`.
2.  **Strip and Recurse:** By definition, a top-level special substring must start with `'1'` and end with `'0'`. We can strip the outer `'1'` and `'0'`, and then recursively maximize the inner valid string `s[i+1 ... j-1]`.
3.  **Reassemble:** After maximizing the inner part, we append the outer `'1'` and `'0'` back to it to get the fully maximized chunk `'1' + maximized_inner + '0'`. We add this chunk to a list of components.
4.  **Sort and Combine:** After parsing the entire string into maximized top-level components, we sort these components in descending order to form the largest possible lexicographical arrangement.
5.  **Return:** Concatenate the sorted components to form the final largest special binary string and return it.

The constraints are extremely small ($N \le 50$), so the algorithm will run very quickly. Its time complexity depends on the depth of valid sequences, but is well within limits for $N=50$.
