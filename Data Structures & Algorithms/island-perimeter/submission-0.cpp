class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        vector<int> dir = {-1, 0, 1, 0, -1};
        vector<vector<int>> cache(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    int p = 4;
                    for (int k = 0; k < 4; k++) {
                        int x = i + dir[k];
                        int y = j + dir[k + 1];
                        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y]) {
                            p--;
                        }
                        cache[i][j] = p;
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res += cache[i][j];
            }
        }
        return res; 
    }
};