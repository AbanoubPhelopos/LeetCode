# 3606. Coupon Code Validator

**Difficulty:** Easy  
**Topics:** Array, String, Sorting  
**Date:** 2025-12-13

## Problem Description

Given arrays `code`, `businessLine`, and `isActive` describing coupons, return valid coupon codes sorted by business line priority and then lexicographically.

**Valid coupon requirements:**
1.  `code[i]` is non-empty and consists only of alphanumeric characters and underscores.
2.  `businessLine[i]` is one of: `"electronics"`, `"grocery"`, `"pharmacy"`, `"restaurant"`.
3.  `isActive[i]` is `true`.

**Sort order:** electronics → grocery → pharmacy → restaurant, then lexicographically within each.

## Example 1

**Input:** `code = ["SAVE20","","PHARMA5","SAVE@20"], businessLine = ["restaurant","grocery","pharmacy","restaurant"], isActive = [true,true,true,true]`  
**Output:** `["PHARMA5","SAVE20"]`

## Example 2

**Input:** `code = ["GROCERY15","ELECTRONICS_50","DISCOUNT10"], businessLine = ["grocery","electronics","invalid"], isActive = [false,true,true]`  
**Output:** `["ELECTRONICS_50"]`

## Constraints

*   `1 <= n <= 100`
*   `0 <= code[i].length, businessLine[i].length <= 100`

## Solution Explanation

### Approach

1.  **Validate:** Check each coupon against the three conditions.
2.  **Prepare for Sorting:** Store valid coupons as `(business_priority, code)` pairs.
3.  **Sort:** Use default pair comparison (first by priority, then by code lexicographically).
4.  **Extract:** Return the sorted codes.

### Complexity
*   **Time Complexity:** `O(N * L + N log N)` where L is max code length.
*   **Space Complexity:** `O(N)`.
