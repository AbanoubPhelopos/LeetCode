

class Solution {
public:
  bool check(long long time, int n, vector<int> &batteries) {
    long long contribution = 0;

    for (int i : batteries) {
      contribution += min(time, 1LL * i);

      if (contribution >= n * time) {
        return true;
      }
    }

    return false;
  }

  long long maxRunTime(int n, vector<int> &batteries) {
    sort(batteries.rbegin(), batteries.rend());
    long long int low = 0;
    long long int high = 1e14;
    long long int ans = 0;

    while (low <= high) {
      long long int mid = (low + high) / 2;

      if (check(mid, n, batteries)) {
        low = mid + 1;
        ans = max(ans, mid);
      } else {
        high = mid - 1;
      }
    }

    return ans;
  }
};
