# 1351. Count Negative Numbers in a Sorted Matrix

**Difficulty**: Easy  
**Topics**: Array, Binary Search, Matrix  
**Date**: December 28, 2025

## Problem Description

Given a `m x n` matrix `grid` which is sorted in **non-increasing** order both row-wise and column-wise, return the number of **negative** numbers in `grid`.

### Example 1
```
Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
```

### Example 2
```
Input: grid = [[3,2],[1,0]]
Output: 0
```

## Solution Approach

### O(m + n) Staircase Approach

Since the rows and columns are sorted in non-increasing order:
- Keep track of position `(i, j)`, starting from the **bottom-left** corner `(n-1, 0)`.
- If the current element `grid[i][j]` is **negative**:
    - Because the row is sorted in descending order, all elements to the right (`grid[i][j...m-1]`) must also be negative.
    - There are `m - j` negative numbers in this row. Add this to the sum.
    - Move **up** to the previous row (`i--`) to check if we can find more negatives earlier in the sequence.
- If the current element is **non-negative**:
    - Because the column is sorted in descending order, all elements above this cell are also non-negative (larger). We need to move **right** (`j++`) to find smaller numbers.

This traversal path moves generally from bottom-left to top-right, creating a "staircase" boundary between positive and negative numbers.

### Code
```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        const int n=grid.size(), m=grid[0].size();
        int sum=0;
        // Start from bottom-left: i = n-1, j = 0
        // Loop while within bounds
        for(int i=n-1, j=0; i>=0 & j<m; ){
            const bool neg=grid[i][j]<0;
            // If negative, add all remaining in row (m-j) to sum.
            // Bitwise trick: -neg is -1 (all 1s) if true, 0 if false.
            sum+=(-neg & (m-j));
            
            // If negative, move up (i--). If positive, move right (j++).
            i-=neg;
            j+=!neg;
        }
        return sum;
    }
};
```
