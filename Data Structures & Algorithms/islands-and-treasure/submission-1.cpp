class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        vector<int> dir = {1, 0, -1, 0, 1};
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j, 0});
                    while (!q.empty()) {
                       vector<int> cur = q.front();
                       q.pop();
                       for (int x = 0; x < 4; x++) {
                            int newi = cur[0] + dir[x];
                            int newj = cur[1] + dir[x + 1];
                            int dist = cur[2] + 1;
                            if (newi >= 0 && newj >= 0 && newi < m && newj < n &&
                                grid[newi][newj] != 0 && grid[newi][newj] != -1) {
                                    if (grid[newi][newj] > dist) {
                                        grid[newi][newj] = dist;
                                        q.push({newi, newj, dist});
                                    }
                            }
                       }
                    }
                }
            }
        }
        return;
    }
};
