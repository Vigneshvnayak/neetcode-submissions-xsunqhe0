class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int dfs(int i, int j, vector<int>& nums) {
        if (i == n) return 0;
        if (dp[i][j + 1] != -1) return dp[i][j + 1];
        dp[i][j + 1] = dfs(i + 1, j, nums);
        if (j == -1 || nums[i] > nums[j]) {
            dp[i][j + 1] = max(dp[i][j + 1], 1 + dfs(i + 1, i, nums));
        }
        return dp[i][j + 1];
    }
    int lengthOfLIS(vector<int>& nums) {
       n = nums.size();
       dp.resize(n, vector<int>(n + 1, -1));
       return dfs(0, -1, nums);
    }
};
