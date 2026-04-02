class Solution {
public:
    int total, n;
    vector<vector<int>> dp;
    int dfs(int i, int sum, int target, vector<int>& nums) {
        if (i == n) return (sum == target);
        if (dp[i][total + sum] != -1) return dp[i][total + sum];
        int sub = dfs(i + 1, sum - nums[i], target, nums);
        int add = dfs(i + 1, sum + nums[i], target, nums);
        dp[i][total + sum] = sub + add;
        return dp[i][total + sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        total = accumulate(nums.begin(), nums.end(), 0);
        dp.resize(n, vector<int>(2 * total + 1, -1));
        return dfs(0, 0, target, nums);
    }
};
