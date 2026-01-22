# 3433. Count Mentions Per User

**Difficulty:** Medium  
**Topics:** Array, Sorting, Simulation  
**Date:** 2025-12-12

## Problem Description

You are given an integer `numberOfUsers` and an array `events` of size `n x 3`.

Each event is either:
*   **MESSAGE:** `["MESSAGE", "timestamp", "mentions_string"]` — mentions users via `id<number>`, `ALL`, or `HERE`.
*   **OFFLINE:** `["OFFLINE", "timestamp", "id"]` — user goes offline for 60 time units.

Return an array where `mentions[i]` is the number of times user `i` was mentioned.

## Example 1

**Input:** `numberOfUsers = 2, events = [["MESSAGE","10","id1 id0"],["OFFLINE","11","0"],["MESSAGE","71","HERE"]]`  
**Output:** `[2,2]`

## Example 2

**Input:** `numberOfUsers = 2, events = [["MESSAGE","10","id1 id0"],["OFFLINE","11","0"],["MESSAGE","12","ALL"]]`  
**Output:** `[2,2]`

## Constraints

*   `1 <= numberOfUsers <= 100`
*   `1 <= events.length <= 100`
*   `1 <= int(events[i][1]) <= 10^5`

## Solution Explanation

### Approach: Sort and Simulate

1.  **Sort Events:** Sort by timestamp, with OFFLINE events processed before MESSAGE events at the same timestamp.
2.  **Simulate:**
    *   Track `next_online_time[i]` for each user (when they'll be online again).
    *   For MESSAGE events:
        *   `ALL`: increment count for all users.
        *   `HERE`: increment count for users where `next_online_time[i] <= cur_time`.
        *   `id<number>`: parse and increment count for each mentioned id.
    *   For OFFLINE events: set `next_online_time[idx] = cur_time + 60`.

### Complexity
*   **Time Complexity:** `O(E log E + E * U)` where E is events, U is users.
*   **Space Complexity:** `O(U)`.
