class Solution {
public:
    int n;
    unordered_map<string, int> dp;
    int dfs(int i, int prev, vector<int>& nums) {
        if (i == n) return 0;
        string key = to_string(nums[i]) + "_" + to_string(prev);
        if (dp.count(key)) return dp[key];
        dp[key] = dfs(i + 1, prev, nums);
        if (prev < nums[i]) {
            dp[key] = max(dp[key], 1 + dfs(i + 1, nums[i], nums));
        }
        return dp[key];
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        return dfs(0, INT_MIN, nums);
    }
};
