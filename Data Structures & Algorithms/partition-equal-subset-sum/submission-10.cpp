class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int target;
    bool dfs(int i, int sum, vector<int>& nums) {
        if (sum == 0) {
            return true;
        }
        if (i == n) {
            return false;
        }
        if (dp[i][sum] != -1) {
            return dp[i][sum] == 1;
        }
        bool skip = dfs(i + 1, sum, nums);
        bool include = false;
        if (nums[i] <= sum) {
            include = dfs(i + 1, sum - nums[i], nums);
        }
        dp[i][sum] = (skip || include) ? 1 : 0;
        return dp[i][sum] == 1;
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        target = sum / 2;
        dp.resize(n, vector<int>(target + 1, -1));
        return dfs(0, target, nums);
    }
};
