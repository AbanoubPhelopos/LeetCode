# 1461. Check If a String Contains All Binary Codes of Size K

**Difficulty:** Medium  
**Topics:** Hash Table, String, Bit Manipulation, Rolling Hash  
**Date:** 2026-02-23

## Problem Description

Given a binary string `s` and an integer `k`, return `true` if every binary code of length `k` is a substring of `s`. Otherwise, return `false`.

**Example 1:**
```
Input: s = "00110110", k = 2
Output: true
Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.
```

**Example 2:**
```
Input: s = "0110", k = 1
Output: true
Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. 
```

**Example 3:**
```
Input: s = "0110", k = 2
Output: false
Explanation: The binary code "00" is of length 2 and does not exist in the array.
```

## Constraints

*   `1 <= s.length <= 5 * 10^5`
*   `s[i]` is either `'0'` or `'1'`.
*   `1 <= k <= 20`

## Solution Approach

The problem asks us to determine if all possible binary strings of length `k` exist as continuous substrings within `s`. The number of unique binary strings of length `k` is exactly $2^k$.

Instead of checking if every possible binary string of length `k` is present in `s`, we can use a sliding window of length `k` across `s` and record every unique length-`k` substring we encounter. At the end, we just check if we have found exactly $2^k$ unique strings.

We can represent each length-`k` substring as an integer value. For instance, if `k = 3`, `"101"` represents the integer `5`. Since $k \le 20$, the maximum integer value we need to represent is $2^{20} - 1$, which easily fits in a standard integer.

To efficiently record the seen binary strings as integers, we can use a rolling hash approach:
1.  **Initialize the window:** Calculate the integer value of the first substring `s[0...k-1]`.
2.  **Slide the window:** As we move the window one character to the right, we can update the numerical value of the window in $O(1)$ time. 
    *   To remove the leftmost character's contribution, we bitwise AND the current value with a mask that has `k-1` ones (`(1 << (k-1)) - 1`).
    *   Then, we shift the remaining bits left by 1 (`mask <<= 1`).
    *   Finally, we bitwise OR the new character's value (0 or 1) at the rightmost position (`mask |= (s[r] - '0')`).
    
We use a `std::bitset` to keep track of the seen integer values because it provides a compact space representation and $O(1)$ time insertion and counting. A size of $1 \ll 20$ (since $1 \le k \le 20$) is sufficient.

By using sliding window logic and a bitset, we process each character in the string in constant $O(1)$ time. Overall time complexity is $O(N)$, where $N$ is the length of `s`, and spaced complexity is $O(2^{\max(K)})$ which corresponds to the size of the bitset.
