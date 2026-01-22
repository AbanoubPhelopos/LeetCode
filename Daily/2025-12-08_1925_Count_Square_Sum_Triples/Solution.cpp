#include <cmath>
#include <iostream>


using namespace std;

class Solution {
public:
  int countTriples(int n) {
    int ans = 0, c;
    for (int i = 3; i <= n; i++) {
      for (int j = 3; j <= n; j++) {
        c = i * i + j * j;
        if (c > n * n)
          break;
        int temp = sqrt(c);
        if (c <= n * n && temp * temp == c)
          ans++;
      }
    }
    return ans;
  }
};
