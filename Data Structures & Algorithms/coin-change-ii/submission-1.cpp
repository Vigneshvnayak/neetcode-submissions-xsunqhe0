class Solution {
public:
    vector<vector<int>> dp;
    int change(int amount, vector<int>& coins) {
      sort(coins.begin(), coins.end());
      dp = vector<vector<int>>(coins.size() + 1, vector<int>(amount + 1, -1));
      return dfs(0, amount, coins);
    }
    int dfs(int i, int amount, vector<int>& coins) {
        if (amount == 0) {
            return 1;
        }
        if (i >= coins.size()) {
            return 0;
        }
        if (dp[i][amount] != -1) {
            dp[i][amount];
        }
        int res = 0;
        if (amount >= coins[i]) {
            res = dfs(i+1, amount, coins);
            res += dfs(i, amount - coins[i], coins);
        }
        dp[i][amount] = res;
        return res;
    }
};
