class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
       int n = costs.size(); 
       vector<vector<int>> dp(n, vector<int>(3, 0));
       for (int i = 0; i < 3; i++) {
            dp[0][i] = costs[0][i];
       }
       for (int i = 1; i < n; i++) {
            for (int c = 0; c < 3; c++) {
                dp[i][c] = costs[i][c] + min(dp[i - 1][(c + 1) % 3], dp[i - 1][(c + 2) % 3]);
            }
       }
       return min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    }
};