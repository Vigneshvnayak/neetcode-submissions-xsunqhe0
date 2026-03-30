class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int total;
    int dfs(int i, int sum, int target, vector<int>& nums) {
        if (i == n) {
            return (sum == target);
        }
        if (dp[i][sum + total] != -1) {
            return dp[i][sum + total];
        }
        int sub = dfs(i + 1, sum - nums[i], target, nums);
        dp[i][sum + total] = sub + dfs(i + 1, sum + nums[i], target, nums);
        return dp[i][sum + total];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        total = accumulate(nums.begin(), nums.end(), 0);
        dp.resize(n, vector<int>(2 * total + 1, -1));
        return dfs(0, 0, target, nums);
    }
};
