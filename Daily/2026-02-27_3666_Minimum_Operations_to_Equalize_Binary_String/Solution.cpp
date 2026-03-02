#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>


using namespace std;

class Solution {
public:
  int minOperations(string s, int k) {
    int n = (int)s.size();
    int z0 = 0;
    for (char c : s)
      if (c == '0')
        z0++;
    if (z0 == 0)
      return 0;

    // dist[z] = min ops to reach state with exactly z zeros
    vector<int> dist(n + 1, INT_MAX);

    // unvisitedByParity[p] stores all unvisited states z with (z % 2 == p)
    vector<set<int>> unvisitedByParity(2);
    for (int z = 0; z <= n; z++)
      unvisitedByParity[z % 2].insert(z);

    queue<int> q;
    q.push(z0);
    dist[z0] = 0;
    unvisitedByParity[z0 % 2].erase(z0);

    while (!q.empty()) {
      int z = q.front();
      q.pop();
      int ones = n - z;
      // x = #zeros flipped in this operation and 0<=x<=k, x<=z, k-x<=ones
      int xMin =
          max(0, k - ones); // == max(0, k - (n - z)) == max(0, k - n + z)
      int xMax = min(k, z);
      if (xMin > xMax)
        continue;

      int L = z + k - 2 * xMax; // smallest z' (largest x)
      int R = z + k - 2 * xMin; // largest  z' (smallest x)

      auto &unvisited = unvisitedByParity[L % 2];
      // Enumerate only UNVISITED states in [L, R] of that parity
      for (auto it = unvisited.lower_bound(L);
           it != unvisited.end() && *it <= R;) {
        int z2 = *it;
        dist[z2] = dist[z] + 1;
        q.push(z2);
        it = next(it);
        unvisited.erase(z2);
      }
    }

    return (dist[0] == INT_MAX) ? -1 : dist[0];
  }
};
