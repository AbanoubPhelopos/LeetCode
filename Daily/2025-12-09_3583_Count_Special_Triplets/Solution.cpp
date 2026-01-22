
class Solution {
public:
  int specialTriplets(vector<int> &nums) {
    int ans = 0;
    int mod = 1e9 + 7;
    unordered_map<long long, long long> freqNext, freqPrev;
    for (auto &i : nums)
      freqNext[i]++;
    for (auto &i : nums) {
      freqNext[i]--;
      if (freqNext[i * 2] && freqPrev[i * 2])
        ans += freqNext[i * 2] % mod * freqPrev[i * 2] % mod;
      ans %= mod;
      freqPrev[i]++;
    }

    return ans % mod;
  }
};
