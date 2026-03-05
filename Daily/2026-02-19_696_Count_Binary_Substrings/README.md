# 696. Count Binary Substrings

**Difficulty:** Easy  
**Topics:** Two Pointers, String  
**Date:** 2026-02-19

## Problem Description

Given a binary string `s`, return the number of non-empty substrings that have the same number of `0`'s and `1`'s, and all the `0`'s and all the `1`'s in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

**Example 1:**
```
Input: s = "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
Notice that some of these substrings repeat and are counted the number of times they occur.
Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
```

**Example 2:**
```
Input: s = "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.
```

## Constraints

*   `1 <= s.length <= 10^5`
*   `s[i]` is either `'0'` or `'1'`.

## Solution Approach

The problem asks us to find substrings where the `0`s and `1`s are grouped consecutively and have the same count (e.g., `"0011"`, `"111000"`).

We can group the string into chunks of contiguous identical characters and just store the lengths of these chunks.
For example, if `s = "110001111000000"`, the lengths of chunks of identical characters would be:
`[2, 3, 4, 6]`.
This corresponds to:
- 2 ones
- 3 zeros
- 4 ones
- 6 zeros

Now, let's look at any two adjacent groups. Suppose we have a group of `u` zeros followed by a group of `v` ones (or vice versa). How many valid substrings can we form that cross the boundary between these two groups?
Since we need an equal amount of `0`s and `1`s, we are limited by the smaller of the two groups. The number of valid substrings we can form is exactly `min(u, v)`.
Using the example `[2, 3, 4, 6]`:
- Between the first two groups (2 ones, 3 zeros), we can form `min(2, 3) = 2` substrings (`"10"`, `"1100"`).
- Between the next two groups (3 zeros, 4 ones), we can form `min(3, 4) = 3` substrings (`"01"`, `"0011"`, `"000111"`).
- Between the last two groups (4 ones, 6 zeros), we can form `min(4, 6) = 4` substrings.

Therefore, the total valid substrings are the sum of `min(group[i], group[i-1])` for all adjacent groups.

**Algorithm:**
1.  Initialize a `group` array to store the counts of contiguous identical characters (or do it iteratively by maintaining the length of the previous group and the current group). In the provided solution, an array of size up to $100000$ captures these counts.
2.  Iterate through the string:
    *   If the current character is the same as the previous one, increment the current group's size.
    *   Otherwise, start a new group with a size of 1.
3.  Iterate over the pairs of adjacent groups, and add `min(group[i], group[i-1])` to the total count (`cnt`).
4.  Return `cnt`.

The time complexity is $O(N)$ because tracing groups and summing takes linear time. The space complexity is $O(N)$ in this array implementation, though it can be optimized to $O(1)$ by only storing the `prev` and `curr` group lengths.
