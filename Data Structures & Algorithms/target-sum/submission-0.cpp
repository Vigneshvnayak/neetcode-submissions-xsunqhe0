class Solution {
public:
    int total;
    vector<vector<int>> dp;
    int findTargetSumWays(vector<int>& nums, int target) {
       total = accumulate(nums.begin(), nums.end(), 0);
       dp = vector<vector<int>>(nums.size(), vector<int>(2 * total + 1, -1));
       return dfs(0, target, 0, nums);
    }
    int dfs(int i, int target, int sum, vector<int> &nums) {
        if (i == nums.size()) {
            return sum == target;
        }
        if (dp[i][total + sum] != -1) {
            return dp[i][total + sum];
        }
        dp[i][total + sum] = dfs(i+1, target, sum + nums[i], nums) + dfs(i+1, target, sum - nums[i], nums);
        return dp[i][total + sum];
    }
};
