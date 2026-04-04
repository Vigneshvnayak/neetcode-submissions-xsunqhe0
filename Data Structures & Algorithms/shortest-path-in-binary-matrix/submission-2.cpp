class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (grid[m - 1][n - 1] || grid[0][0]) return -1;
        queue<pair<int,int>> q;
        vector<int> dir = {1, -1, -1, 1, 1, 0, -1, 0, 1};
        q.push({0, 0});
        grid[0][0] = 1;
        while (!q.empty()) {
            pair<int, int> t = q.front();
            q.pop();
            int i = t.first;
            int j = t.second;
            if (i == m - 1 && j == n - 1) {
                return grid[i][j];
            }
            for (int k = 0; k < 8; k++) {
                int newi = i + dir[k];
                int newj = j + dir[k + 1];
                if (newi < 0 || newj < 0 || newi >= m || newj >= n || grid[newi][newj]) {
                    continue;
                }
                grid[newi][newj] = 1 + grid[i][j];
                q.push({newi, newj});
            }
        }
        return -1;
    }
};