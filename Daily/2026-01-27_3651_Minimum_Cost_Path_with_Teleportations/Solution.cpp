

class Solution {
public:
  int minCost(vector<vector<int>> &grid, int k) {
    int n = grid.size();
    int m = grid[0].size();

    int maxVal = 0;
    for (const auto &row : grid) {
      for (int val : row)
        maxVal = max(maxVal, val);
    }

    // dp[i][j] = Min cost to reach (n-1, m-1) from (i, j)
    vector<vector<int>> dp(n, vector<int>(m));

    // temp[v] = Min cost starting from ANY cell with value 'v'
    vector<int> temp(maxVal + 1, 1e9);
    vector<int> best(maxVal + 1);

    // Base Case
    // The cost is incurred when ENTERING a cell.
    // We consider the target reached, so starting at target has 0 *additional*
    // cost.
    temp[grid[n - 1][m - 1]] = 0;

    // Initialization (k=0)
    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {
        if (i == n - 1 && j == m - 1) {
          dp[i][j] = 0;
          continue;
        }

        int down = (i + 1 < n) ? dp[i + 1][j] + grid[i + 1][j] : 1e9;
        int right = (j + 1 < m) ? dp[i][j + 1] + grid[i][j + 1] : 1e9;

        dp[i][j] = min(down, right);

        if (dp[i][j] != 1e9) {
          temp[grid[i][j]] = min(temp[grid[i][j]], dp[i][j]);
        }
      }
    }

    // Layers (k > 0)
    for (int x = 0; x < k; x++) {
      best[0] = temp[0];
      for (int v = 1; v <= maxVal; v++) {
        best[v] = min(best[v - 1], temp[v]);
      }

      for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
          if (i == n - 1 && j == m - 1)
            continue;

          int down = (i + 1 < n) ? dp[i + 1][j] + grid[i + 1][j] : 1e9;
          int right = (j + 1 < m) ? dp[i][j + 1] + grid[i][j + 1] : 1e9;
          int walkCost = min(down, right);

          int teleportCost = best[grid[i][j]];

          dp[i][j] = min(walkCost, teleportCost);

          if (dp[i][j] != 1e9) {
            temp[grid[i][j]] = min(temp[grid[i][j]], dp[i][j]);
          }
        }
      }
    }

    return dp[0][0];
  }
};
