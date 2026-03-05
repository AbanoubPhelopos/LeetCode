# 1758. Minimum Changes To Make Alternating Binary String

**Difficulty:** Easy  
**Topics:** String, Math  
**Date:** 2026-03-05

## Problem Description

You are given a string `s` consisting only of the characters `'0'` and `'1'`. In one operation, you can change any `'0'` to `'1'` or vice versa.

The string is called alternating if no two adjacent characters are equal. For example, the string `"010"` is alternating, while the string `"0100"` is not.

Return the minimum number of operations needed to make `s` alternating.

**Example 1:**
```
Input: s = "0100"
Output: 1
Explanation: If you change the last character to '1', s will be "0101", which is alternating.
```

**Example 2:**
```
Input: s = "10"
Output: 0
Explanation: s is already alternating.
```

**Example 3:**
```
Input: s = "1111"
Output: 2
Explanation: You need two operations to reach "0101" or "1010".
```

## Constraints

*   `1 <= s.length <= 10^4`
*   `s[i]` is either `'0'` or `'1'`.

## Solution Approach

The goal is to find the minimum number of character flips to make the string alternating. 
A binary string is alternating if it follows one of two exact patterns:
1.  Starts with `'0'`: `"01010101..."`
2.  Starts with `'1'`: `"10101010..."`

Notice that these two patterns are exact bitwise complements of each other. That means if a character at index `i` matches the first pattern, it will *not* match the second pattern, and vice versa.

Therefore, if we calculate the number of changes required to convert the given string `s` into the first pattern (let's call this count `c`), the number of changes required to convert it into the second pattern will simply be `n - c`, where `n` is the length of the string.

This allows us to only explicitly count the differences against one pattern.
-   We iterate over the string, keeping track of the expected character `j` (starting at `0` and flipping it using `x ^= 1` in each step).
-   If the current character in `s` matches the expected character `j`, we increment our count `c`. (Wait, the code implementation basically checks `s[n] - '0' == j`. If it *equals* the expected character `j`, `c` is the count of characters that are *correct* for the pattern starting with `1` but the logic still works, or it counts the differences for the pattern starting with `0`. The provided code actually checks `s[n] - '0' == j`, where `j` oscillates `0, 1, 0, 1...`. So `c` counts how many characters match the `"1010..."` pattern reversed or `"0101..."` depending on what you track.)
-   Specifically, in the given code: `j` starts at `0`. `j` goes `0, 1, 0, 1...`. If `s[n] - '0' == j`, it means `s[n]` matches the pattern `"0101..."`. So `c` counts the number of characters that *already match* the `"0101..."` pattern. To make it exactly `"0101..."`, we need to change `n - c` characters. To make it exactly `"1010..."`, we need to change the `c` characters that matched `"0101..."`. Hence, the operations needed are `c` and `n - c`.
-   The minimum number of operations is just `min(c, n - c)`.

This approach evaluates the string in a single pass taking $O(N)$ time complexity and $O(1)$ space.
