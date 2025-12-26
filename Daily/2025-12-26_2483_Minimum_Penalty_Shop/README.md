# 2483. Minimum Penalty for a Shop

**Difficulty**: Medium  
**Topics**: String, Prefix Sum  
**Date**: December 26, 2025

## Problem Description

You are given the customer visit log of a shop represented by a 0-indexed string `customers` consisting only of characters 'N' and 'Y':

- if the `i-th` character is 'Y', it means that customers come at the `i-th` hour
- whereas 'N' indicates that no customers come at the `i-th` hour.

If the shop closes at the `j-th` hour (`0 <= j <= n`), the penalty is calculated as follows:
- For every hour when the shop is open and no customers come, the penalty increases by 1.
- For every hour when the shop is closed and customers come, the penalty increases by 1.

Return the earliest hour at which the shop must be closed to incur a minimum penalty.

Note that if a shop closes at the `j-th` hour, it means the shop is closed at the hour `j`.

### Example 1
```
Input: customers = "YYNY"
Output: 2
Explanation: 
- Closing at 0: Penalty = 1+1+0+1 = 3 (Y, Y, N, Y missed/open empty) -> logic:
  - Open 0 hrs. Closed at 0. Customers at 0,1,3. Penalty = 3.
  - Wait, let's re-read:
  - Open: mismatch if 'N'. Closed: mismatch if 'Y'.
  - Close at 0: Open range []. Closed range [0, 1, 2, 3]. 'Y' at 0, 1, 3. Penalty 3.
- Closing at 2: Open [0, 1]. Closed [2, 3].
  - 0: 'Y' (ok). 1: 'Y' (ok).
  - 2: 'N' (ok). 3: 'Y' (penalty).
  - Total penalty = 1.
```

## Solution Approach

### Prefix and Suffix Sums

To determine the penalty for closing at hour `i`:
1.  **Open Penalty** (Hours `0` to `i-1`): We incur a penalty for every 'N' encountered while open.
2.  **Closed Penalty** (Hours `i` to `n-1`): We incur a penalty for every 'Y' encountered while closed.

We can precompute these values:
- `N_P[i]`: Number of 'N's in `customers[0...i-1]`.
- `Y_P[i]`: Number of 'Y's in `customers[i...n-1]`.

The total penalty for closing at hour `i` is simply `N_P[i] + Y_P[i]`.
We calculate this sum for all possible closing times (`0` to `n`) and find the minimum.

### Code
```cpp
class Solution {
public:
    int bestClosingTime(string c) {
        int n=c.size();
        vector<int>N_P(n+1,0),Y_P(n+1,0);
        
        // Mark occurrences
        for(int i=0;i<n;i++)
            if(c[i]=='Y') Y_P[i]=1;
            else N_P[i+1]=1;
        
        // Suffix sum for Y (Y_P[i] = count of Y in range [i, n-1])
        for(int i=n;i>0;i--) Y_P[i-1]=Y_P[i-1]+Y_P[i];
        
        // Prefix sum for N (N_P[i] = count of N in range [0, i-1])
        for(int i=1;i<=n;i++) N_P[i] = N_P[i]+N_P[i-1];

        int minPenalty = Y_P[0]+N_P[0];
        int ans = 0;
        
        for(int i=1;i<=n;i++){
            int penalty = Y_P[i]+N_P[i];
            if(penalty < minPenalty){
                minPenalty = penalty;
                ans = i;
            }
        }
        return ans;
    }
};
```
