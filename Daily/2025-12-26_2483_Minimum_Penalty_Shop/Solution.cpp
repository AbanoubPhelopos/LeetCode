
class Solution {
public:
  int bestClosingTime(string c) {
    int n = c.size();
    vector<int> N_P(n + 1, 0), Y_P(n + 1, 0);

    for (int i = 0; i < n; i++)
      if (c[i] == 'Y')
        Y_P[i] = 1;
      else
        N_P[i + 1] = 1;

    for (int i = n; i > 0; i--)
      Y_P[i - 1] = Y_P[i - 1] + Y_P[i];
    for (int i = 1; i <= n; i++)
      N_P[i] = N_P[i] + N_P[i - 1];

    int temp = Y_P[0] + N_P[0], ans = 0;
    for (int i = 1; i <= n; i++) {
      if ((Y_P[i] + N_P[i]) < temp) {
        temp = Y_P[i] + N_P[i];
        ans = i;
      }
    }
    return ans;
  }
};
