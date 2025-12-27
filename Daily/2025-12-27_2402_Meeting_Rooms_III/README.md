# 2402. Meeting Rooms III

**Difficulty**: Hard  
**Topics**: Array, Sorting, Heap (Priority Queue), Simulation  
**Date**: December 27, 2025

## Problem Description

You are given an integer `n`. There are `n` rooms numbered from `0` to `n - 1`.

You are given a 2D integer array `meetings` where `meetings[i] = [starti, endi]` means that a meeting will be held during the **half-closed** time interval `[starti, endi)`. All the values of `starti` are unique.

Meetings are allocated to rooms in the following manner:

1.  Each meeting will take place in the unused room with the **lowest number**.
2.  If there are no available rooms, the meeting will be **delayed** until a room becomes free. The delayed meeting should have the **same duration** as the original meeting.
3.  When a room becomes unused, meetings that have an **earlier original start time** should be given the room.

Return the **number of the room** that held the most meetings. If there are multiple rooms, return the room with the **lowest number**.

A half-closed interval `[a, b)` is the interval between `a` and `b` including `a` and not including `b`.

### Example 1
```
Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
Output: 0
Explanation:
- Time 0: Room 0 takes [0,10].
- Time 1: Room 1 takes [1,5].
- Time 2: Room 0 busy (until 10), Room 1 busy (until 5). Meeting [2,7] delayed.
- Time 3: Both busy. Meeting [3,4] delayed.
- Time 5: Room 1 frees up. Meeting [2,7] starts in Room 1. New range [5, 10) (duration 5).
- Time 10: Room 0 frees up. Meeting [3,4] starts in Room 0. New range [10, 11) (duration 1).
- Total: Room 0 -> 2 meetings. Room 1 -> 2 meetings. Return 0 (min index).
```

## Solution Approach

### Simulation

The problem asks us to simulate the meeting allocation process.

1.  **Sort Meetings**: Format requires processing meetings by start time, so we sort `meetings` by `start` time.
2.  **Track Room Availability**: We need to know when each room will be free. We can use an array `timer` of size `n`, where `timer[i]` stores the time when room `i` becomes free. Initially, all are 0.
3.  **Process Each Meeting**:
    - For a meeting `[start, end]`, duration `dur = end - start`.
    - We check for an available room (where `timer[i] <= start`).
    - **Case 1: Available Room Found**:
        - Pick the one with the smallest index `i`.
        - Update `timer[i] = end`.
        - Increment `count[i]`.
    - **Case 2: No Room Available**:
        - We must wait. We find the room that finishes the *soonest* (smallest `timer[i]`). If ties, pick smallest index.
        - The new start time will be `timer[earliestRoom]`.
        - The new end time will be `timer[earliestRoom] + dur`.
        - Update `timer[earliestRoom] += dur`.
        - Increment `count[earliestRoom]`.
4.  **Result**: Find the index with the maximum count.

### Code
```cpp
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        vector<int> count(n);
        vector<long long> timer(n);

        int itr = 0;

        while (itr < meetings.size()) {
            int start = meetings[itr][0];
            int end = meetings[itr][1];
            long long dur = end - start;

            int room = -1;
            long long earliest = LLONG_MAX;
            int earliestRoom = -1;

            for (int i = 0; i < n; i++) {
                if (timer[i] < earliest) {
                    earliest = timer[i];
                    earliestRoom = i;
                }
                if (timer[i] <= start) {
                    room = i;
                    break;
                }
            }

            if (room != -1) {
                timer[room] = end;
                count[room]++;
            } else {
                timer[earliestRoom] += dur;
                count[earliestRoom]++;
            }

            itr++;
        }

        int max = 0, idx = 0;
        for (int i = 0; i < n; i++) {
            if (count[i] > max) {
                max = count[i];
                idx = i;
            }
        }

        return idx;
    }
};
```
