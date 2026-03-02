# 1356. Sort Integers by The Number of 1 Bits

**Difficulty:** Easy  
**Topics:** Array, Bit Manipulation, Sorting, Counting  
**Date:** 2026-02-25

## Problem Description

You are given an integer array `arr`. Sort the integers in the array in ascending order by the number of `1`'s in their binary representation and in case of two or more integers have the same number of `1`'s you have to sort them in ascending order.

Return the array after sorting it.

**Example 1:**
```
Input: arr = [0,1,2,3,4,5,6,7,8]
Output: [0,1,2,4,8,3,5,6,7]
Explantion: [0] is the only integer with 0 bits.
[1,2,4,8] all have 1 bit.
[3,5,6] have 2 bits.
[7] has 3 bits.
The sorted array by bits is [0,1,2,4,8,3,5,6,7]
```

**Example 2:**
```
Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
Output: [1,2,4,8,16,32,64,128,256,512,1024]
Explantion: All integers have 1 bit in the binary representation, you should just sort them in ascending order.
```

## Constraints

*   `1 <= arr.length <= 500`
*   `0 <= arr[i] <= 10^4`

## Solution Approach

The problem requires us to sort an array of integers based on two primary conditions:
1.  **Primary condition:** The number of `1` bits (set bits) in the binary representation of the integer, in ascending order.
2.  **Secondary condition:** If two integers have the same number of `1` bits, they should be sorted by their actual integer values in ascending order.

We can achieve this by using the standard sorting algorithm provided by our language's standard library along with a custom comparator.

In C++, we can use `std::sort` and define a lambda function as the custom comparator.
To count the number of set bits efficiently, we can use the built-in compiler function `__builtin_popcount(x)`. This function is highly optimized and often translates to a single CPU instruction (like `popcnt` on x86 architectures), making the bit-counting step extremely fast.

In the custom comparator for two elements `a` and `b`:
- Calculate the number of set bits for `a` and `b` (`ca = __builtin_popcount(a)` and `cb = __builtin_popcount(b)`).
- If the bit counts are different (`ca != cb`), return `ca < cb` to sort by the number of set bits.
- If the bit counts are the same, return `a < b` to sort by the integer values.

This approach effectively and concisely solves the problem with a time complexity of `O(N log N)` where `N` is the number of elements in the array, dictated by the sorting algorithm. The space complexity is `O(1)` or `O(log N)` depending on the sorting implementation of the language.
