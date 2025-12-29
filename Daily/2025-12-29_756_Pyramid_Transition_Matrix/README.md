# 756. Pyramid Transition Matrix

**Difficulty**: Medium  
**Topics**: Bit Manipulation, Depth-First Search, Breadth-First Search  
**Date**: December 29, 2025

## Problem Description

You are stacking blocks to form a pyramid. Each block has a color, which is represented by a single letter. Each row of blocks contains one less block than the row beneath it and is centered on top.

To make the pyramid aesthetically pleasing, there are only specific triangular patterns that are allowed. A triangular pattern consists of a single block stacked on top of two blocks. The patterns are given as a list of three-letter strings `allowed`, where the first two characters of a pattern represent the left and right bottom blocks respectively, and the third character is the top block.

- For example, "ABC" represents a triangular pattern with a 'C' block stacked on top of an 'A' (left) and 'B' (right) block. 

Given `bottom` (the bottom row of blocks as a string) and `allowed`, return `true` if you can build the pyramid all the way to the top such that every triangular pattern in the pyramid is in `allowed`, or `false` otherwise.

### Example 1
```
Input: bottom = "BCD", allowed = ["BCC","CDE","CEA","FFF"]
Output: true
Explanation: 
- Level 3 (base): B C D
- Level 2: "BC" -> "C" (pattern "BCC"). "CD" -> "E" (pattern "CDE"). Layer: "CE"
- Level 1: "CE" -> "A" (pattern "CEA"). Top: "A"
All patterns allowed.
```

### Example 2
```
Input: bottom = "AAAA", allowed = ["AAB","AAC","BCD","BBE","DEF"]
Output: false
Explanation: No way to reach the top.
```

## Solution Approach

### Recursive DFS with Memoization

The problem asks if we can reach a single block at the top. We can simulate the process row by row.

1.  **State Representation**: `solve(index, new_layer, current_layer, length)`
    - `index`: Current position in the `current_layer` we are processing.
    - `new_layer`: The next layer being built.
    - `current_layer`: The layer currently acting as the base.
    - `length`: Size of the `current_layer`.

2.  **Base Case**: 
    - If `length == 1`, we have reached the top of the pyramid. Return `true`.

3.  **Recursive Step**:
    - If we have filled the `new_layer` (i.e., `index == length - 1`), we move to the next level:
        - Call `solve(0, "", new_layer, length - 1)`.
        - Use memoization (`dp`) to store results of `new_layer` to avoid re-computing.
    - Otherwise, for the pair of blocks `current_layer[index]` and `current_layer[index+1]`:
        - Find all allowed "top" blocks from our map `mp` (constructed from `allowed`).
        - For each possible top block, append it to `new_layer` and recursively call `solve(index + 1, ...)`
        - If any path returns `true`, propagate it back.

4.  **Optimization**:
    - Use a map `mp` to quickly lookup valid parents for a base pair. `mp["AB"] -> ["C"]`.
    - Use a map `dp` for memoization of layers (`dp[layer] = true/false`).

### Code
```cpp
class Solution {
public:
    map<string,vector<string>> mp;
    map<string,bool> dp;
    
    bool solve(int ind, string newlayer, string oldlayer, int n)
    {
        // If the current layer has only 1 block, we reached the top!
        if(n==1) return true;
        
        // If we finished building the New Layer, start processing IT as the Old Layer
        if(ind==n-1)
        {
            if (dp.count(newlayer)) return dp[newlayer];
            return dp[newlayer]=solve(0,"",newlayer,n-1);
        }

        // Look at the pair (current block, next block) in the Old Layer
        string tmp = oldlayer.substr(ind,2);

        // If no allowed pattern exists for this pair, this path is dead
        if(!mp.count(tmp)) return false;

        // Try every possible block that can sit on top of this pair
        for(auto x:mp[tmp]){
            // Determine if placing 'x' allows solving the rest of the layer
            if(solve(ind+1,newlayer+x,oldlayer,n)) 
                return true;
        }
        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int n = bottom.size();

        // Preprocess allowed patterns into a map for O(1) lookup
        // Key: "BaseLeftBaseRight", Value: List of "Top" blocks
        for(auto x:allowed){
            mp[x.substr(0,2)].push_back(x.substr(2));
        }

        return solve(0,"",bottom,n);
    }
};
```
