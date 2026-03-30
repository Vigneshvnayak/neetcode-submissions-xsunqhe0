class Solution {
public:
    vector<vector<int>> dp;
    int maxProfit(vector<int>& prices) {
       dp = vector<vector<int>>(prices.size(), vector<int>(2, -1));
       return dfs(0, 0, prices);
    }
    int dfs(int i, int buy, vector<int>& prices) {
       if (i >= prices.size()) {
           return 0;
       }
       if (dp[i][buy] != -1) {
           return dp[i][buy];
       }
       int cooldown = dfs(i+1, buy, prices);
       if (buy == 0) {
           int b = dfs(i+1, 1, prices) - prices[i];
           dp[i][buy] = max(b, cooldown);
       } else {
           int s = dfs(i+2, 0, prices) + prices[i];
           dp[i][buy] = max(s, cooldown);
       }
       return dp[i][buy];
    }
};
