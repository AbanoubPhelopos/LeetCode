# 2141. Maximum Running Time of N Computers

**Difficulty:** Hard  
**Topics:** Array, Binary Search, Greedy, Sorting  
**Date:** 2025-12-01

## Problem Description

You have `n` computers. You are given the integer `n` and a 0-indexed integer array `batteries` where the `ith` battery can run a computer for `batteries[i]` minutes. You are interested in running all `n` computers simultaneously using the given batteries.

Initially, you can insert at most one battery into each computer. After that and at any integer time moment, you can remove a battery from a computer and insert another battery any number of times. The inserted battery can be a totally new battery or a battery from another computer. You may assume that the removing and inserting processes take no time.

**Note:** The batteries cannot be recharged.

Return the maximum number of minutes you can run all the `n` computers simultaneously.

## Example 1

**Input:** `n = 2, batteries = [3,3,3]`  
**Output:** `4`  
**Explanation:**  
Initially, insert battery 0 into the first computer and battery 1 into the second computer.  
After two minutes, remove battery 1 from the second computer and insert battery 2 instead.  
At the end of the third minute, battery 0 is drained, and you need to remove it from the first computer and insert battery 1 instead.  
By the end of the fourth minute, battery 1 is also drained.  
We can run the two computers simultaneously for at most 4 minutes.

## Example 2

**Input:** `n = 2, batteries = [1,1,1,1]`  
**Output:** `2`

## Constraints

*   `1 <= n <= batteries.length <= 10^5`
*   `1 <= batteries[i] <= 10^9`

## Solution Explanation

We want to find the maximum time `T` such that we can run `n` computers for `T` minutes each.

### Key Insight: Binary Search on Time
The answer is monotonic: if we can run for time `T`, we can definitely run for time `T-1`. This allows us to **binary search** on the answer.

### Feasibility Check (`check(T, n, batteries)`)
Given a target time `T`, can we run `n` computers for `T` minutes?
*   Each computer needs `T` total minutes of power.
*   Total power needed: `n * T` minutes.
*   Each battery `b` can contribute `min(b, T)` minutes.
    *   If `b >= T`, it can power one computer for the full `T` minutes.
    *   If `b < T`, it can only contribute `b` minutes (it will be swapped between computers or used partially).
*   If `sum(min(batteries[i], T)) >= n * T`, then we can run for time `T`.

### Algorithm
1.  **Binary Search:** Search for `T` in the range `[0, total_battery_capacity / n]` (or a safe upper bound like `10^14`).
2.  **Check Feasibility:** For each `mid = (low + high) / 2`, check if `sum(min(batteries[i], mid)) >= n * mid`.
3.  **Update Answer:** If feasible, move `low = mid + 1` and record `ans = mid`. Otherwise, `high = mid - 1`.

### Complexity
*   **Time Complexity:** `O(m * log(maxT))`, where `m` is the number of batteries and `maxT` is the search range (up to `10^14`). `log(10^14)` is about 47.
*   **Space Complexity:** `O(1)` (or `O(m log m)` for sorting if optimization is done, though the provided solution's sorting is `O(m log m)`). Note: The sorting in this solution is done but not strictly necessary for the `check` function logic; it might be for an early exit optimization.
