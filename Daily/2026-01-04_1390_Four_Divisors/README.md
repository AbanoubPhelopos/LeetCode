# 1390. Four Divisors

**Difficulty:** Medium  
**Topics:** Math  
**Date:** 2026-01-04

## Problem Description

Given an integer array `nums`, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return `0`.

## Example 1

**Input:** `nums = [21,4,7]`  
**Output:** `32`  
**Explanation:**  
*   21 has 4 divisors: 1, 3, 7, 21. Sum = 32.
*   4 has 3 divisors: 1, 2, 4.
*   7 has 2 divisors: 1, 7.  
The answer is the sum of divisors of 21 only.

## Example 2

**Input:** `nums = [21,21]`  
**Output:** `64`

## Example 3

**Input:** `nums = [1,2,3,4,5]`  
**Output:** `0`

## Constraints

*   `1 <= nums.length <= 10^4`
*   `1 <= nums[i] <= 10^5`

## Solution Explanation

We need to identify numbers that have exactly 4 divisors. A number has exactly 4 divisors if:
1.  It is the product of two distinct prime numbers `p` and `q` (`n = p * q`). The divisors are `1, p, q, n`. The sum is `1 + p + q + n`.
2.  It is the cube of a prime number `p` (`n = p^3`). The divisors are `1, p, p^2, n`. The sum is `1 + p + p^2 + n`.

### Approach

1.  **Sieve of Eratosthenes:** Since `nums[i] <= 10^5`, we can precompute primes up to `sqrt(10^5) ≈ 316`. This allows us to quickly factorize each number.
2.  **Factorization:** For each number `x` in `nums`:
    *   Iterate through the precomputed primes.
    *   Count distinct prime factors (`cntPF`) and their exponents (`e`).
    *   If we find any prime factor with `e > 1` (unless it's `e=3` and it's the *only* prime factor), the number cannot have exactly 4 divisors (except the `p^3` case).
    *   If `cntPF > 2`, it has more than 4 divisors.
3.  **Conditions:**
    *   If `cntPF == 2` (distinct primes `p, q`) and both have exponent 1, then Divisor Count is `(1+1)*(1+1) = 4`. Sum is `(1+p)(1+q) = 1 + p + q + pq`.
    *   If `cntPF == 1` and exponent is 3 (`n = p^3`), Divisor Count is `3+1 = 4`. Sum is `1 + p + p^2 + p^3`.
4.  **Optimization:** The solution uses a `Div4` array to cache results for numbers already processed.

This approach efficiently handles the constraints.
