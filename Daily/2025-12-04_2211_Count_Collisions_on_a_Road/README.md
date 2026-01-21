# 2211. Count Collisions on a Road

**Difficulty:** Medium  
**Topics:** String, Stack, Simulation  
**Date:** 2025-12-04

## Problem Description

There are `n` cars on an infinitely long road. The cars are numbered from `0` to `n - 1` from left to right and each car is present at a unique point.

You are given a 0-indexed string `directions` of length `n`. `directions[i]` can be either `'L'`, `'R'`, or `'S'` denoting whether the `ith` car is moving towards the left, towards the right, or staying at its current point respectively. Each moving car has the same speed.

The number of collisions can be calculated as follows:
*   When two cars moving in opposite directions collide with each other, the number of collisions increases by 2.
*   When a moving car collides with a stationary car, the number of collisions increases by 1.

After a collision, the cars involved can no longer move and will stay at the point where they collided.

Return the total number of collisions that will happen on the road.

## Example 1

**Input:** `directions = "RLRSLL"`  
**Output:** `5`

## Example 2

**Input:** `directions = "LLRR"`  
**Output:** `0`

## Constraints

*   `1 <= directions.length <= 10^5`
*   `directions[i]` is either `'L'`, `'R'`, or `'S'`.

## Solution Explanation

Cars that escape the road without collision:
*   Cars at the left end moving 'L' will never collide.
*   Cars at the right end moving 'R' will never collide.

All other cars ('L', 'R', or 'S') in the middle segment will eventually be involved in collisions.

### Approach

1.  **Trim Escaping Cars:**
    *   Skip all leading 'L' cars from the left.
    *   Skip all trailing 'R' cars from the right.
2.  **Count Collisions in Remaining Segment:**
    *   Every 'R' car in this segment will eventually collide (either with an 'S', an 'L', or a stopped car) → count +1.
    *   Every 'L' car in this segment will also collide (with a stopped car or an 'R' coming from the left) → count +1.
    *   'S' cars don't add to the count directly but act as stoppers.

In essence, the answer is: `(number of 'R' in remaining segment) + (number of 'L' in remaining segment)`.

### Complexity
*   **Time Complexity:** `O(N)` single pass.
*   **Space Complexity:** `O(1)`.
