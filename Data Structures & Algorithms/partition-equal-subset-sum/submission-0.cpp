class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = 0;
        for (int i=0; i<nums.size(); i++) {
            s += nums[i];
        }
        if (s % 2 != 0) {
            return false;
        }
        int target = s / 2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return dfs(0, target, dp, nums);
    }
    bool dfs(int i, int target, vector<vector<int>> &dp, vector<int> &nums) {
        if (i == nums.size()) {
            return target == 0;
        }
        if (target < 0) {
            return  false;
        }
        if (dp[i][target] != -1) {
            return dp[i][target];
        }
        dp[i][target] = dfs(i+1, target, dp, nums) || dfs(i+1, target - nums[i], dp, nums);
        return dp[i][target];
    }
};
