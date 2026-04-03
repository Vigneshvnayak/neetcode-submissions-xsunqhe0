class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        vector<int> dir = {0, -1, 0, 1, 0};
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        int time = 0;
        while (!q.empty() && fresh) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                pair<int, int> cur = q.front();
                q.pop();
                int x = cur.first;
                int y = cur.second;
                for (int k = 0; k < 4; k++) {
                    int newx = x + dir[k];
                    int newy = y + dir[k + 1];
                    if (newx >= 0 && newy >= 0 && newx < m && newy < n && 
                    grid[newx][newy] == 1) {
                        fresh--;
                        grid[newx][newy] = 2;
                        q.push({newx, newy});
                    }
                }
            }
            time++;
        }
        return fresh > 0 ? -1 : time;
    }
};
