# 712. Minimum ASCII Delete Sum for Two Strings

**Difficulty:** Medium  
**Topics:** String, Dynamic Programming  
**Date:** 2026-01-10

## Problem Description

Given two strings `s1` and `s2`, return the lowest ASCII sum of deleted characters to make two strings equal.

## Example 1

**Input:** `s1 = "sea", s2 = "eat"`  
**Output:** `231`  
**Explanation:**  
Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.  
Deleting "t" from "eat" adds 116 to the sum.  
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.

## Example 2

**Input:** `s1 = "delete", s2 = "leet"`  
**Output:** `403`  
**Explanation:**  
Deleting "dee" from "delete" to turn the string into "let", adds 100[d] + 101[e] + 101[e] to the sum.  
Deleting "e" from "leet" adds 101[e] to the sum.  
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.  
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.

## Constraints

*   `1 <= s1.length, s2.length <= 1000`
*   `s1` and `s2` consist of lowercase English letters.

## Solution Explanation

The problem asks for the minimum cost (sum of ASCII values) of deleted characters to make two strings equal. This is equivalent to finding the **Maximum ASCII Sum Common Subsequence**.

If we find the longest common subsequence where "length" is defined by the sum of ASCII values of the characters, we essentially keep the most "valuable" characters common to both strings.

### Approach

1.  **Total ASCII Sum:** First, calculate the sum of all ASCII values in both `s1` and `s2`. Let this be `total_sum`.
2.  **Max Common ASCII Sum:** We use Dynamic Programming (similar to Longest Common Subsequence) to find the maximum ASCII sum of a subsequence common to both strings.
    *   `dp[i][j]` stores the maximum ASCII sum of a common subsequence between `s1[0...i-1]` and `s2[0...j-1]`.
    *   If `s1[i] == s2[j]`, then we include this character: `dp[i+1][j+1] = dp[i][j] + ascii(s1[i])`.
    *   If `s1[i] != s2[j]`, we take the maximum by skipping a character from either `s1` or `s2`: `dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j])`.
3.  **Result:** The logic is that the characters *not* in the common subsequence must be deleted.
    *   `Deleted Sum = (Sum of s1) + (Sum of s2) - 2 * (Max Common ASCII Sum)`
    *   We subtract `2 * Max Common ASCII Sum` because the characters in the common subsequence are present in both original strings sum but are *kept* (not deleted), so we essentially remove their contribution from the "tobe deleted" pool from both sides.

This approach is efficient with time complexity `O(n*m)` and space complexity `O(n*m)`.
