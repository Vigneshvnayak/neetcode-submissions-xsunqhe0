class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> memo(m+1, vector<int>(n+1, 0));
        memo[m-1][n-1] = 1;
        if (obstacleGrid[m-1][n-1]) return 0;
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (!obstacleGrid[i][j]){
                    memo[i][j] += memo[i+1][j] + memo[i][j+1];
                }
            }
        }
        return memo[0][0];
    }
};