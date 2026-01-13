# 1161. Maximum Level Sum of a Binary Tree

**Difficulty:** Medium  
**Topics:** Tree, Breadth-First Search, Binary Tree  
**Date:** 2026-01-06

## Problem Description

Given the `root` of a binary tree, the level of its root is `1`, the level of its children is `2`, and so on.

Return the **smallest** level `x` such that the sum of all the values of nodes at level `x` is **maximal**.

## Example 1

**Input:** `root = [1,7,0,7,-8,null,null]`  
**Output:** `2`  
**Explanation:**  
*   Level 1 sum = 1.
*   Level 2 sum = 7 + 0 = 7.
*   Level 3 sum = 7 + -8 = -1.  
The maximum sum is 7, so we return level 2.

## Example 2

**Input:** `root = [989,null,10250,98693,-89388,null,null,null,-32127]`  
**Output:** `2`

## Constraints

*   The number of nodes in the tree is in the range `[1, 10^4]`.
*   `-10^5 <= Node.val <= 10^5`

## Solution Explanation

To find the level with the maximum sum, we can perform a **Breadth-First Search (BFS)** traversal (also known as Level Order Traversal).

### Approach

1.  **Queue Initialization:** Use a queue to facilitate level-order traversal, initializing it with the `root`.
2.  **Level Traversal:** Use a `while` loop that continues as long as the queue is not empty.
3.  **Process Level:** Inside the loop, determine the number of nodes at the current level (`size = q.size()`). Iterate exactly `size` times to process all nodes at this level.
4.  **Calculate Sum:** Sum the values of all nodes in the current level. Add their children to the queue for the next level.
5.  **Update Maximum:** Compare the current level's sum (`levelSum`) with the global maximum found so far (`maxSum`). If `levelSum > maxSum`, update `maxSum` and record the current `level` as `maxLevel`.
    *   Note: Since we need the *smallest* level in case of a tie, using `>` (strict greater than) ensures we keep the first occurrence of the maximum sum.
6.  **Increment Level:** Increment the level counter after processing each level.

This approach visits every node exactly once, resulting in a time complexity of `O(N)`, where `N` is the number of nodes. Space complexity is `O(W)`, where `W` is the maximum width of the tree.
