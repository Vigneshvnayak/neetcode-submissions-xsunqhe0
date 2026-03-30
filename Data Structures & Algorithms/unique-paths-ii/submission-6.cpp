class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> memo(m+1, vector<int>(n+1, 0));
        memo[1][1] = 1;
        if (obstacleGrid[m-1][n-1]) return 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (!obstacleGrid[i - 1][j - 1]){
                    memo[i][j] += memo[i-1][j] + memo[i][j-1];
                }
            }
        }
        return memo[m][n];
    }
};