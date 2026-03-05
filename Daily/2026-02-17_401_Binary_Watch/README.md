# 401. Binary Watch

**Difficulty:** Easy  
**Topics:** Backtracking, Bit Manipulation  
**Date:** 2026-02-17

## Problem Description

A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6 LEDs on the bottom to represent the minutes (0-59). Each LED represents a zero or one, with the least significant bit on the right.

Given an integer `turnedOn` which represents the number of LEDs that are currently on (ignoring the PM), return all possible times the watch could represent. You may return the answer in **any order**.

The hour must not contain a leading zero.
*   For example, `"01:00"` is not valid. It should be `"1:00"`.

The minute must consist of two digits and may contain a leading zero.
*   For example, `"10:2"` is not valid. It should be `"10:02"`.

**Example 1:**
```
Input: turnedOn = 1
Output: ["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]
```

**Example 2:**
```
Input: turnedOn = 9
Output: []
```

## Constraints

*   `0 <= turnedOn <= 10`

## Solution Approach

A naive approach might involve combinatorial generation (choosing `turnedOn` LEDs out of 10), but there is a much simpler and strictly bounded approach.

There are only a total of $12$ possible hours (0 to 11) and $60$ possible minutes (0 to 59). This means there are exactly $12 \times 60 = 720$ possible valid times a watch could ever represent.

Instead of figuring out which LEDs are turned on and mapping them to hours and minutes, we can iterate over all $720$ valid times and check if the number of set bits (LEDs turned on) equals `turnedOn`.

Algorithm:
1.  Iterate `hour` from 0 to 11.
2.  Iterate `minute` from 0 to 59.
3.  Count the number of set bits in `hour` representing the LEDs on top, and the number of set bits in `minute` representing the LEDs on the bottom. We can efficiently count set bits using built-in compiler functions like `__builtin_popcount` in C++.
4.  If the total number of set bits equals `turnedOn`, format the time as `H:MM`. Ensure that minutes less than 10 are padded with a leading zero.
5.  Add the string to the result vector.

This brute-force approach guarantees we consider all valid times and perfectly format them. It operates in $O(1)$ constant time ($720$ iterations at most) and takes $O(1)$ auxiliary space (ignoring the space to hold the output strings), making it both optimally fast and easy to implement.
