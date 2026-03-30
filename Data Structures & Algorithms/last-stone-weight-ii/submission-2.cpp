class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int total_sum;
    int dfs(int i, int sum, int target, vector<int>& stones) {
        if (sum >= target || i == n) {
            return abs(total_sum - 2 * sum);
        }
        if (dp[i][sum] != -1) {
            return dp[i][sum];
        }
        dp[i][sum] = dfs(i + 1, sum, target, stones);
        if (sum + stones[i] <= target) {
            dp[i][sum] = min(dp[i][sum], dfs(i + 1, sum + stones[i], target, stones));
        }
        return dp[i][sum];
    }
    int lastStoneWeightII(vector<int>& stones) {
       n = stones.size();
       total_sum = accumulate(stones.begin(), stones.end(), 0);
       int target = (total_sum + 1) / 2;
       dp.resize(n, vector<int>(target + 1, -1));
       return dfs(0, 0, target, stones);
    }
};