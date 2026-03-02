#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

// variant
short R1[200]; // pos for rightmoost 1

class Solution {
public:
  static int minSwaps(vector<vector<int>> &grid) {
    const int n = grid.size();
    for (int i = 0; i < n; i++) {
      R1[i] = -1;
      for (int j = n - 1; j >= 0; j--) {
        if (grid[i][j] == 1) {
          R1[i] = j;
          break;
        }
      }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (R1[i] <= i)
        continue;
      int j = i + 1;
      // Find 1st j st R1[j]<=i
      for (; j < n && R1[j] > i; j++)
        ;

      // impossible
      if (j == n)
        return -1;

      // the correct Bubble at position i
      cnt += j - i;
      auto tmp = R1[j];
      // move elements in the range [i, j) to the range ending at j+1
      copy_backward(R1 + i, R1 + j, R1 + j + 1);
      R1[i] = tmp;
    }
    return cnt;
  }
};
