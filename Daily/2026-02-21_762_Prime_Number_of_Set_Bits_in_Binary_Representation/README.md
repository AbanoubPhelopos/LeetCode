# 762. Prime Number of Set Bits in Binary Representation

**Difficulty:** Easy  
**Topics:** Math, Bit Manipulation  
**Date:** 2026-02-21

## Problem Description

Given two integers `left` and `right`, return the count of numbers in the inclusive range `[left, right]` having a prime number of set bits in their binary representation.

Recall that the number of set bits an integer has is the number of `1`'s present when written in binary.

For example, `21` written in binary is `10101`, which has `3` set bits.

**Example 1:**
```
Input: left = 6, right = 10
Output: 4
Explanation:
6  -> 110 (2 set bits, 2 is prime)
7  -> 111 (3 set bits, 3 is prime)
8  -> 1000 (1 set bit, 1 is not prime)
9  -> 1001 (2 set bits, 2 is prime)
10 -> 1010 (2 set bits, 2 is prime)
4 numbers have a prime number of set bits.
```

**Example 2:**
```
Input: left = 10, right = 15
Output: 5
Explanation:
10 -> 1010 (2 set bits, 2 is prime)
11 -> 1011 (3 set bits, 3 is prime)
12 -> 1100 (2 set bits, 2 is prime)
13 -> 1101 (3 set bits, 3 is prime)
14 -> 1110 (3 set bits, 3 is prime)
15 -> 1111 (4 set bits, 4 is not prime)
5 numbers have a prime number of set bits.
```

## Constraints

*   `1 <= left <= right <= 10^6`
*   `0 <= right - left <= 10^4`

## Solution Approach

The constraints state that `right` is up to $10^6$. Since $10^6 < 2^{20}$, the maximum number of set bits any number in the given range can have is 19 (for example $524287 = 2^{19}-1$, which has 19 set bits). Thus, we only need to check if a bit count is prime up to 19.

The prime numbers up to 19 are: `2, 3, 5, 7, 11, 13, 17, 19`.

We can solve this problem straightforwardly:
1.  **Iterate through the range:** Create a loop from `left` to `right` (inclusive).
2.  **Count Set Bits:** For each number `i` in the range, count its set bits. This can be done efficiently in C++ using `__builtin_popcount(i)`.
3.  **Check for Primality:** Check if the resulting bit count is one of the predefined prime numbers. We can use a boolean array or a bitmask to do this $O(1)$ check. In this solution, an array `isPrime` is pre-populated where `isPrime[p] = true` for the chosen primes.
4.  **Accumulate:** If the bit count is prime, increment the sum counter.

Finally, return the accumulated sum. The time complexity is $O(right - left)$ and space complexity is $O(1)$ for the `isPrime` boolean array mapping.
