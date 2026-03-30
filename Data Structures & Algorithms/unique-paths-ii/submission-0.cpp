class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
       int m = grid.size();
       int n = grid[0].size();
       vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
       dp[m-1][n-1] = 1;
       if (grid[m-1][n-1]) {
        return 0;
       }
       for (int i = m-1; i >= 0; i--){
            for (int j=n-1; j >=0; j--) {
                if (grid[i][j]) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] += dp[i+1][j];
                    dp[i][j] += dp[i][j+1];
                }
            }
       }
       return dp[0][0];
    }
};