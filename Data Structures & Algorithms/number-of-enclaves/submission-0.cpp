class Solution {
public:
    void dfs (int i, int j, int m, int n, vector<vector<int>>& grid) {
        queue<vector<int>> q;
        vector<int> dir = {0, 1, 0, -1, 0};
        grid[i][j] = 0;
        q.push({i, j});
        while (!q.empty()) {
            vector<int> c = q.front();
            q.pop();
            for (int x = 0; x < 4; x++) {
                int ni = c[0] + dir[x];
                int nj = c[1] + dir[x + 1];
                if (ni >= 0 && nj >= 0 && ni < m && nj < n &&
                    grid[ni][nj] == 1) {
                        grid[ni][nj] = 0;
                        q.push({ni, nj});
                }
            }
        }
        return;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 1) {
                dfs(0, i, m, n, grid);
            }
        }
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) {
                dfs(i, 0, m, n, grid);
            }
        }
        for (int i = 0; i < m; i++) {
            if (grid[i][n - 1] == 1) {
                dfs(i, n - 1, m, n, grid);
            }
        }
        for (int i = 0; i < n; i++) {
            if (grid[m - 1][i] == 1) {
                dfs(m - 1, i, m, n, grid);
            }
        }
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    res += 1;
                }
            }
        }
        return res;
    }
};