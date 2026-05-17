class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1]) return 0;
        vector<vector<int>> grid(m + 1, vector<int>(n + 1, 0));
        grid[m - 1][n - 1] = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (obstacleGrid[i][j]) continue;
                grid[i][j] += grid[i + 1][j] + grid[i][j + 1];
            }
        }
        return grid[0][0];
    }
};
/*
0 0 0
0 0 0
0 1 0

0 0 0 0
0 0 0 0
0 0 1 0
0 0 0 0
*/