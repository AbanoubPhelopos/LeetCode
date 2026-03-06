# 1784. Check if Binary String Has at Most One Segment of Ones

**Difficulty:** Easy  
**Topics:** String  
**Date:** 2026-03-06

## Problem Description

Given a binary string `s` without leading zeros, return `true` if `s` contains at most one contiguous segment of ones. Otherwise, return `false`.

**Example 1:**
```
Input: s = "1001"
Output: false
Explanation: The ones do not form a contiguous segment.
```

**Example 2:**
```
Input: s = "110"
Output: true
```

## Constraints

*   `1 <= s.length <= 100`
*   `s[i]` is either `'0'` or `'1'`.
*   `s[0]` is `'1'`.

## Solution Approach

The strings in this problem always start with `'1'` (no leading zeros). This means there is inherently at least one segment of ones at the very beginning of the string.

To have "at most one contiguous segment of ones", the entire string must consist of some number of `1`s followed by some number of `0`s (or no `0`s at all). Any `1` appearing *after* a `0` implies that there is a second segment of ones.

Therefore, we can efficiently check this by identifying the positions of the `0`s and `1`s:
1.  **Find the first `0`:** We can find the index of the first occurrence of `'0'` using `s.find('0')`. Let this be `i0`.
    * If there are no `0`s in the string (`i0 == -1`), then the entire string is just one big segment of ones. In this case, we return `true`.
2.  **Find the last `1`:** We can find the index of the last occurrence of `'1'` using `s.find_last_of('1')`. Let this be `i1`.
3.  **Compare indices:** For the string to have only one segment of ones at the beginning, all `1`s must appear before all `0`s. This means the index of the first `'0'` must be strictly greater than the index of the last `'1'` (`i0 > i1`).
    * If `i0 < i1`, it implies there is a `'1'` that occurs after a `'0'`, meaning there are at least two separate segments of ones, so we return `false`.

This approach uses standard string search functions, operating seamlessly in $O(N)$ time, where $N$ is the length of the string, and requires $O(1)$ auxiliary space. Alternatively, we could just check if the substring `"01"` exists anywhere in the string, which would also indicate multiple segments.
