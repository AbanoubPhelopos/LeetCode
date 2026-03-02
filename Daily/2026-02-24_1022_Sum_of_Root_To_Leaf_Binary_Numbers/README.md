# 1022. Sum of Root To Leaf Binary Numbers

**Difficulty:** Easy  
**Topics:** Tree, Depth-First Search, Binary Tree  
**Date:** 2026-02-24

## Problem Description

You are given the `root` of a binary tree where each node has a value `0` or `1`. Each root-to-leaf path represents a binary number starting with the most significant bit.

For example, if the path is `0 -> 1 -> 1 -> 0 -> 1`, then this could represent `01101` in binary, which is `13`.
For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers.

The test cases are generated so that the answer fits in a **32-bits** integer.

**Example 1:**
![tree](https://assets.leetcode.com/uploads/2019/04/04/sum-of-root-to-leaf-binary-numbers.png)
```
Input: root = [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
```

**Example 2:**
```
Input: root = [0]
Output: 0
```

## Constraints

*   The number of nodes in the tree is in the range `[1, 1000]`.
*   `Node.val` is `0` or `1`.

## Solution Approach

The goal is to calculate the sum of the binary numbers formed by the paths from the root to all leaves in a binary tree. Since the problem involves traversing from root to specific endpoints (leaves), Depth-First Search (DFS) is a natural fit.

As we traverse down the tree from the root, we need to maintain an ongoing binary number (`curr`). 
At each node, we basically append the current node's value (`0` or `1`) to the end of our ongoing binary number. In binary arithmetic, appending a digit to the right is equivalent to shifting the number one position to the left (multiplying by 2) and adding the new digit. 
Thus, the operation to update the current number is: `curr = curr * 2 + node->val` (or equivalently `curr = (curr << 1) | node->val`).

We can implement this using a recursive helper function `dfs(TreeNode* node, int curr)`:
1.  **Base Case (Null Node):** If the current node is `nullptr`, it doesn't form a path to a leaf, so we return `0`.
2.  **Update current value:** We calculate `curr = curr * 2 + node->val`.
3.  **Base Case (Leaf Node):** If the current node is a leaf (both `left` and `right` children are `nullptr`), we have reached the end of a path. We return the computed `curr` value for this path.
4.  **Recursive Step:** For an internal node, the total sum of the paths passing through it is the sum of the paths in its left subtree plus the sum of the paths in its right subtree. We recursively call `dfs` on the left and right children, passing the updated `curr` value, and return their sum: `return dfs(node->left, curr) + dfs(node->right, curr)`.

The time complexity is $O(N)$ where $N$ is the number of nodes in the tree, because we visit each node exactly once. The space complexity is $O(H)$ where $H$ is the height of the tree, corresponding to the maximum depth of the recursive call stack (which is $O(\log N)$ for a balanced tree and $O(N)$ for a skewed tree).
