
class Solution {
public:
  long long maximumHappinessSum(vector<int> &h, int k) {
    long long ans = 0;

    sort(h.begin(), h.end());
    long long cnt = 0, idx = h.size() - 1, temp = 0;

    while (k--) {
      temp = h[idx] - cnt;
      if (temp <= 0)
        break;
      else
        ans += temp;
      idx--;
      cnt++;
    }

    return ans;
  }
};
