

class Solution {
public:
  static const unsigned long long INF = ULLONG_MAX;
  unsigned long long dist[201][201];
  unsigned long long dp[1001];

  unordered_map<string, int> id;
  unordered_set<int> lens;

  long long minimumCost(string source, string target, vector<string> &original,
                        vector<string> &changed, vector<int> &cost) {

    int m = original.size();
    int n = source.size();

    id.clear();
    lens.clear();

    int sz = 0;
    // Initialize dist with INF (using -1 cast to unsigned long long is
    // equivalent to all 1s binary representation)
    memset(dist, 255, sizeof(dist));

    for (int i = 0; i < m; i++) {
      if (!id.count(original[i])) {
        id[original[i]] = sz++;
        lens.insert(original[i].size());
      }
      if (!id.count(changed[i])) {
        id[changed[i]] = sz++;
      }
      int u = id[original[i]];
      int v = id[changed[i]];
      dist[u][v] = min(dist[u][v], (unsigned long long)cost[i]);
    }

    // Self loops are 0
    for (int i = 0; i < sz; i++)
      dist[i][i] = 0;

    // Floyd-Warshall
    for (int k = 0; k < sz; k++)
      for (int i = 0; i < sz; i++)
        if (dist[i][k] != INF)
          for (int j = 0; j < sz; j++)
            if (dist[k][j] != INF)
              dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    // DP state
    memset(dp, 255, sizeof(dp));
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
      if (dp[i] == INF)
        continue;

      // Option 1: Characters are same, cost 0 to skip
      if (source[i] == target[i])
        dp[i + 1] = min(dp[i + 1], dp[i]);

      // Option 2: Try to match substrings from 'original'
      for (int L : lens) {
        if (i + L > n)
          continue;

        string s = source.substr(i, L);
        string t = target.substr(i, L);

        if (id.count(s) && id.count(t)) {
          int u = id[s];
          int v = id[t];
          if (dist[u][v] != INF)
            dp[i + L] = min(dp[i + L], dp[i] + dist[u][v]);
        }
      }
    }

    return dp[n] == INF ? -1 : (long long)dp[n];
  }
};

auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 'c';
}();
