class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int dfs(int i, int amt, vector<int>& coins) {
        if (amt == 0) return 1;
        if (i == n) return 0;
        if (dp[i][amt] != -1) return dp[i][amt];
        int skip = dfs(i + 1, amt, coins);
        int include = 0;
        if (coins[i] <= amt) {
            include = dfs(i, amt - coins[i], coins);
        }
        dp[i][amt] = skip + include;
        return dp[i][amt];
    }
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        sort(coins.begin(), coins.end());
        dp.resize(n, vector<int>(amount + 1, -1));
        return dfs(0, amount, coins);
    }
};
