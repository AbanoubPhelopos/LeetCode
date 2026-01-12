# 1339. Maximum Product of Splitted Binary Tree

**Difficulty:** Medium  
**Topics:** Tree, Depth-First Search, Binary Tree  
**Date:** 2026-01-07

## Problem Description

Given the `root` of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.

Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it **modulo** `10^9 + 7`.

Note that you need to maximize the answer before taking the mod and not after taking it.

## Example 1

**Input:** `root = [1,2,3,4,5,6]`  
**Output:** `110`  
**Explanation:** Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10).

## Example 2

**Input:** `root = [1,null,2,3,4,null,null,5,6]`  
**Output:** `90`  
**Explanation:** Remove the red edge and get 2 binary trees with sum 15 and 6. Their product is 90 (15*6).

## Constraints

*   The number of nodes in the tree is in the range `[2, 5 * 10^4]`.
*   `1 <= Node.val <= 10^4`

## Solution Explanation

We need to remove one edge to split the tree into two subtrees. Removing an edge connecting a node to its parent effectively separates the subtree rooted at that node from the rest of the tree.

### Approach

1.  **Calculate Total Sum:** First, we traverse the entire tree to calculate the `total_sum` of all node values.
2.  **Maximize Product:**
    *   If we remove the edge above a node (let's say node `u`), the sum of one subtree will be the sum of the subtree rooted at `u` (`sub_sum`).
    *   The sum of the other subtree will be `total_sum - sub_sum`.
    *   The product is `sub_sum * (total_sum - sub_sum)`.
3.  **Algorithm:**
    *   Perform a DFS traversal to calculate the sum of every subtree.
    *   For each subtree sum calculated, compute the potential product: `sub_sum * (total_sum - sub_sum)`.
    *   Keep track of the maximum product found.
    *   Finally, return the maximum product modulo `10^9 + 7`.

The provided solution uses a two-pass DFS. Pass 1 computes the `total`. Pass 2 re-calculates sums (or could use memoization/values stored) and updates the `ans` with the maximum product found.
