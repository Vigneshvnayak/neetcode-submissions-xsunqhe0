class Solution {
public:
    bool canPartition(vector<int>& nums) {
       int n = nums.size();
       int sum = accumulate(nums.begin(), nums.end(), 0);
       if (sum % 2 != 0) return false;
       int half = sum / 2;
       vector<vector<int>> dp(n + 1, vector<int>(half + 1, false));
       for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
       }
       for (int i = 1; i <= n; i++) {
            for (int s = 1; s <= half; s++) {
                bool skip = dp[i - 1][s];
                if (nums[i - 1] <= s) {
                    dp[i][s] = dp[i - 1][s - nums[i - 1]];
                }
                dp[i][s] |= skip;
            }
       }
       return dp[n][half];
    }
};
