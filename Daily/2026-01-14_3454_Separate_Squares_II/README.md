# 3454. Separate Squares II

**Difficulty:** Hard  
**Topics:** Array, Math, Geometry, Sorting, Heap (Priority Queue), Segment Tree  
**Date:** 2026-01-14

## Problem Description

You are given a 2D integer array `squares`. Each `squares[i] = [xi, yi, li]` represents the coordinates of the bottom-left point and the side length of a square parallel to the x-axis.

Find the minimum y-coordinate value of a horizontal line such that the total area covered by squares above the line equals the total area covered by squares below the line.

Answers within `10^-5` of the actual answer will be accepted.

**Note:** Squares may overlap. Overlapping areas should be counted **only once** in this version.

## Example 1

**Input:** `squares = [[0,0,1],[2,2,1]]`  
**Output:** `1.00000`  
**Explanation:**  
Any horizontal line between `y = 1` and `y = 2` results in an equal split, with 1 square unit above and 1 square unit below. The minimum y-value is 1.

## Example 2

**Input:** `squares = [[0,0,2],[1,1,1]]`  
**Output:** `1.00000`  
**Explanation:**  
Since the blue square overlaps with the red square, it will not be counted again. Thus, the line `y = 1` splits the squares into two equal parts.

## Constraints

*   `1 <= squares.length <= 5 * 10^4`
*   `0 <= xi, yi <= 10^9`
*   `1 <= li <= 10^9`
*   The total area of all the squares will not exceed `10^15`.

## Solution Explanation

The key difference between this version and "Separate Squares I" is that overlapping areas are counted only once. This suggests we're dealing with the union of geometric shapes.

### Approach: Plane Sweep (Sweep-Line Algorithm)

1.  **Coordinate Compression (Y-axis):** Since we need to find a `y` coordinate, and the geometry changes only at the bottom and top edges of the squares, we can process the plane in horizontal strips defined by these y-events.
    *   **Events:** For each square `[x, y, l]`, we create two events:
        *   `Type 1` (Enter): At `y`, adding a square spanning `[x, x + l]`.
        *   `Type -1` (Exit): At `y + l`, removing a square spanning `[x, x + l]`.
    *   Sort all events by their `y` coordinate.

2.  **Processing Strips:**
    *   Iterate through the sorted events.
    *   The interval between the current event's `y` and the previous event's `prev_y` defines a horizontal strip.
    *   Within this strip, the set of active vertical intervals (ranges on the X-axis) remains constant.
    *   **Union of Widths:** We calculate the length of the union of all active X-intervals. This gives the effective "width" of the union of squares at this Y-level.
    *   **Area Accumulation:** `Area = width * (curr_y - prev_y)`. We accumulate this area.

3.  **Active Interval Management:**
    *   We maintain a list of active intervals. When an "Enter" event occurs, we add the interval. When an "Exit" event occurs, we remove it.
    *   To find the "Union Width", we sort the active intervals and merge overlapping ones.

4.  **Finding the Split Line:**
    *   Once we have processed all strips and calculated the `total_area`, we seek the target area `total_area / 2.0`.
    *   We iterate through our calculated strips again. If adding a strip's area exceeds the target, the split line lies within this strip.
    *   We can compute the exact position by interpolation: `y = start_y + (target - accumulated) / width`.

This approach correctly handles overlaps by computing the union of widths for every uniform horizontal slice.
