
class Solution {
public:
  int countPartitions(vector<int> &nums) {

    int ans = 0, sum = 0;
    for (int i = 0; i < nums.size(); i++)
      sum += nums[i];

    int localsum = 0;
    for (int j = 0; j < nums.size() - 1; j++) {
      localsum += nums[j];
      if (abs(localsum - (sum - localsum)) % 2 == 0)
        ans++;
    }

    return ans;
  }
};
