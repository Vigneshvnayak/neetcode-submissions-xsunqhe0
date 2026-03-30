class Solution {
public:
    int dfs(int r, int c, int m, int n, vector<vector<int>>& grid) {
        if (r < 0 || c < 0 || r >= m || c >= n) {
            return 1;
        }
        if (!grid[r][c]) {
            return 1;
        }
        if (grid[r][c] == -1) {
            return 0;
        }
        grid[r][c] = -1;
        int p = 0;
        p = dfs(r + 1, c, m, n, grid);
        p += dfs(r, c + 1, m, n, grid);
        p += dfs(r - 1, c, m, n, grid);
        p += dfs(r, c - 1, m, n, grid);
        return p;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    return dfs(i, j, m, n, grid);
                }
            }
        }
        return 0;
    }
};