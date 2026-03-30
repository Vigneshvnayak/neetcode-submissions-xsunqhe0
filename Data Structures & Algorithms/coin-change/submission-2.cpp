class Solution {
public:
    int n;
    vector<vector<long long>> dp;
    long long dfs(int i, int amt, vector<int>& coins) {
        if (amt == 0) return 0;
        if (dp[i][amt] != -1) return dp[i][amt];
        long long skip = INT_MAX;
        if (i + 1 < n) {
            skip = dfs(i + 1, amt, coins);
        }
        long long include = INT_MAX;
        if (coins[i] <= amt) {
            include = min(include, 1 + dfs(i, amt - coins[i], coins));
        }
        dp[i][amt] = min(skip, include);
        return dp[i][amt];
    }
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        dp.resize(n, vector<long long>(amount + 1, -1));
        long long res = dfs(0, amount, coins);
        return (res == INT_MAX) ? -1 : static_cast<int>(res);
    }
};
