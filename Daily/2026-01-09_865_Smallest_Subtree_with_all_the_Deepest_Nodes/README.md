# 865. Smallest Subtree with all the Deepest Nodes

**Difficulty:** Medium  
**Topics:** Tree, Breadth-First Search, Depth-First Search, Hash Table, Binary Tree  
**Date:** 2026-01-09

## Problem Description

Given the `root` of a binary tree, the depth of each node is the shortest distance to the root.

Return the smallest subtree such that it contains all the deepest nodes in the original tree.

A node is called the **deepest** if it has the largest depth possible among any node in the entire tree.

The subtree of a node is a tree consisting of that node, plus the set of all descendants of that node.

*Note: This question is the same as 1123: Lowest Common Ancestor of Deepest Leaves*

## Example 1

**Input:** `root = [3,5,1,6,2,0,8,null,null,7,4]`  
**Output:** `[2,7,4]`  
**Explanation:**  
We return the node with value 2, colored in yellow in the diagram.  
The nodes coloured in blue are the deepest nodes of the tree.  
Notice that nodes 5, 3 and 2 contain the deepest nodes in the tree but node 2 is the smallest subtree among them, so we return it.

## Example 2

**Input:** `root = [1]`  
**Output:** `[1]`  
**Explanation:** The root is the deepest node in the tree.

## Example 3

**Input:** `root = [0,1,3,null,2]`  
**Output:** `[2]`  
**Explanation:** The deepest node in the tree is 2, the valid subtrees are the subtrees of nodes 2, 1 and 0 but the subtree of node 2 is the smallest.

## Constraints

*   The number of nodes in the tree will be in the range `[1, 500]`.
*   `0 <= Node.val <= 500`
*   The values of the nodes in the tree are unique.

## Solution Explanation

The problem asks for the standard **Lowest Common Ancestor (LCA)** of all the deepest nodes in the tree.

### Approach

1.  **Find all Deepest Nodes:** We can use Breadth-First Search (BFS) to traverse the tree level by level. The nodes in the last level accessed are the deepest nodes.
    *   We can also maintain a `parent` map to keep track of each node's parent, which allows us to traverse upwards.

2.  **Find the Ancestor:**
    *   Once we have the set of all deepest nodes (from the last level of BFS), we intuitively "move up" the tree from all of them simultaneously.
    *   If multiple nodes share the same parent, they merge into that parent.
    *   We repeat this process: take the set of current nodes, replace them with their parents (using a Set to avoid duplicates).
    *   We stop when the set size becomes 1. That single node is the root of the smallest subtree containing all deepest nodes (the LCA).

This approach ensures we find the lowest code that is an ancestor to all deepest nodes efficiently.
