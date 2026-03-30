class Solution {
public:
    int maxCoins(vector<int>& nums) {
       nums.insert(nums.begin(), 1);
       nums.push_back(1);
       int n = nums.size();
       vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
       return dfs(nums, 1, n-2, dp);
    }
    int dfs(vector<int> &nums, int l, int r,
    vector<vector<int>>&dp) {
        if (l > r) {
            return 0;
        }
        if (dp[l][r] != -1) {
            return dp[l][r];
        }
        dp[l][r] = 0;
        for (int i=l; i<=r; i++) {
            int c = nums[l-1] * nums[i] * nums[r+1];
            c += dfs(nums, l, i-1, dp) + dfs(nums, i+1, r, dp);
            dp[l][r] = max(dp[l][r], c);
        }
        return dp[l][r];
    }
};
