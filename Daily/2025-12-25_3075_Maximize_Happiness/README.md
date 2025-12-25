# 3075. Maximize Happiness of Selected Children

**Difficulty**: Medium  
**Topics**: Arrays, Greedy, Sorting  
**Date**: December 25, 2025

## Problem Description

You are given an array `happiness` of length `n`, and a positive integer `k`.

There are `n` children standing in a queue, where the `i-th` child has happiness value `happiness[i]`. You want to select `k` children from these `n` children in `k` turns.

In each turn, when you select a child, the happiness value of all the children that have not been selected till now decreases by 1. Note that the happiness value cannot become negative and gets decremented only if it is positive.

Return the maximum sum of the happiness values of the selected children you can achieve by selecting `k` children.

### Example 1
```
Input: happiness = [1,2,3], k = 2
Output: 4
Explanation: 
- Pick 3: Remaining [0,1]. Sum = 3.
- Pick 1: Remaining [0]. Sum = 3 + 1 = 4.
```

### Example 2
```
Input: happiness = [1,1,1,1], k = 2
Output: 1
Explanation: 
- Pick 1: Remaining [0,0,0]. Sum = 1.
- Pick 0: Remaining [0,0]. Sum = 1 + 0 = 1.
```

## Solution Approach

The core idea is **Greedy**. To maximize sum, we should pick the children with the highest happiness values first.

1.  **Sort the array**: By sorting `happiness` in ascending order, we can access the largest elements from the end.
2.  **Iterate `k` times**: We pick the largest available element.
3.  **Decrement Logic**:
    - Each time we pick a child, the *effective* value of subsequent children decreases by `1` for each turn that has passed.
    - If `cnt` is the number of turns passed (children already picked), the value of the current child is `value - cnt`.
    - We must ensure this value doesn't drop below 0 (`max(0, value - cnt)`).
4.  **Accumulate**: Add the effective value to the answer.
5.  **Break Early**: Since we are picking in descending order, if `value - cnt <= 0`, any subsequent values will also be 0 (since they are smaller or equal, and `cnt` will only increase). We can stop early.

### Code
```cpp
class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        long long ans=0;

        sort(h.begin(),h.end());
        long long cnt=0,idx=h.size()-1,temp=0;

        while(k--){
            temp = h[idx]-cnt;
            if(temp<=0) break;
            else ans+=temp;
            idx--;cnt++;
        }

        return ans;
    }
};
```
