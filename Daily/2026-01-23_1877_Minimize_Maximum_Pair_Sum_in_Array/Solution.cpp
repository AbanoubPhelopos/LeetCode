
class Solution {
public:
  int minPairSum(vector<int> &nums) {
    int min_val = INT_MAX, max_val = INT_MIN;
    int freq[100001] = {0};
    for (int num : nums) {
      if (num < min_val)
        min_val = num;
      if (num > max_val)
        max_val = num;
      freq[num]++;
    }

    int max_sum = 0;
    int l = min_val, r = max_val;

    while (l <= r) {
      if (freq[l] == 0) {
        l++;
      } else if (freq[r] == 0) {
        r--;
      } else {
        max_sum = max(max_sum, l + r);
        freq[l]--;
        freq[r]--;
      }
    }
    return max_sum;
  }
};
