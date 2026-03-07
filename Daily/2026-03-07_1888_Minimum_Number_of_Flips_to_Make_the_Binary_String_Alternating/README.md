# 1888. Minimum Number of Flips to Make the Binary String Alternating

**Difficulty:** Medium  
**Topics:** String, Sliding Window, Greedy  
**Date:** 2026-03-07

## Problem Description

You are given a binary string `s`. You are allowed to perform two types of operations on the string in any sequence:

*   **Type-1:** Remove the character at the start of the string `s` and append it to the end of the string.
*   **Type-2:** Pick any character in `s` and flip its value, i.e., if its value is `'0'` it becomes `'1'` and vice-versa.

Return the minimum number of type-2 operations you need to perform such that `s` becomes alternating.

The string is called alternating if no two adjacent characters are equal. For example, the strings `"010"` and `"1010"` are alternating, while the string `"0100"` is not.

**Example 1:**
```
Input: s = "111000"
Output: 2
Explanation: Use the first operation two times to make s = "100011".
Then, use the second operation on the third and sixth elements to make s = "101010".
```

**Example 2:**
```
Input: s = "010"
Output: 0
Explanation: The string is already alternating.
```

**Example 3:**
```
Input: s = "1110"
Output: 1
Explanation: Use the second operation on the second element to make s = "1010".
```

## Constraints

*   `1 <= s.length <= 10^5`
*   `s[i]` is either `'0'` or `'1'`.

## Solution Approach

There are only two possible target alternating patterns:
- **Pattern A:** `"010101..."` (starts with `'0'`)
- **Pattern B:** `"101010..."` (starts with `'1'`)

The Type-1 operation (rotate left) allows us to try every possible rotation of the string. Instead of physically rotating the string, we can simulate this by imagining `s` doubled: `t = s + s`. Every window of length `n` in `t` corresponds to a rotation of `s`.

**Key Insight:** For a character at position `i` in the string, whether it matches Pattern A or Pattern B depends purely on the parity of `i`. Specifically:
- If `s[i]` is `'0'` and `i` is even → matches Pattern A
- If `s[i]` is `'1'` and `i` is odd → matches Pattern A
- In other words: `(s[i] ^ i) & 1 == 0` means it already matches Pattern A without a flip

We maintain two counters `op[0]` and `op[1]`:
- `op[0]` = number of flips needed to match **Pattern A** (`"0101..."`) in the current window
- `op[1]` = number of flips needed to match **Pattern B** (`"1010..."`) in the current window

Since `op[0] + op[1] = n` (every character either matches A or B), we take `min(op[0], op[1])` as the cost.

**Algorithm:**
1. Initialize `op[0]` and `op[1]` by scanning the first window (the original string). For each `i`: if `(s[i] ^ i) & 1 == 1`, the character mismatches Pattern A, so increment `op[1]` (wrong for B as a consequence). Otherwise increment `op[0]`.
2. Record `res = min(op[0], op[1])`.
3. Slide the window across `t = s + s`. When character `s[i]` rotates out from the left (position `i` in the window) and then enters from the right at position `n + i`, we update both counters accordingly.
4. Track the minimum across all windows.

The time complexity is $O(N)$ for the single pass through the string with constant-time updates. Space is $O(1)$.
