class Solution {
public:
    bool canPartition(vector<int>& nums) {
       int n = nums.size();
       int total = accumulate(nums.begin(), nums.end(), 0);
       if (total % 2 != 0) return false;
       int target = total / 2;
       vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
       for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
       }
       for (int i = 1; i <= target; i++) {
            for (int j = 1; j <= n; j++) {
                bool skip = dp[j - 1][i];
                bool include = false;
                if (nums[j - 1] <= i) {
                    include |= dp[j - 1][i - nums[j - 1]];
                }
                dp[j][i] = skip | include;
            }
       }
       return dp[n][target];
    }
};
