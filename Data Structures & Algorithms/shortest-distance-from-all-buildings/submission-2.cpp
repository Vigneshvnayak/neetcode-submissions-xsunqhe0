class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
       int m = grid.size();
       int n = grid[0].size();
       queue<vector<int>> q;
       vector<vector<int>> dist(m, vector<int>(n, 0));
       vector<vector<int>> count(m, vector<int>(n, 0));
       vector<vector<bool>> visit;
       int building = 0;
       vector<int> dir = {0, 1, 0, -1, 0};
       for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    building++;
                    visit.assign(m, vector<bool>(n, false));
                    q.push({i, j, 0});
                    visit[i][j] = true;
                    while (!q.empty()) {
                        vector<int> cur = q.front();
                        q.pop();
                        int x = cur[0];
                        int y = cur[1];
                        int d = cur[2];
                        for (int k = 0; k < 4; k++) {
                            int newx = x + dir[k];
                            int newy = y + dir[k + 1];
                            if (newx >= 0 && newy >= 0 && newx < m && newy < n && !visit[newx][newy] && grid[newx][newy] == 0) {
                                count[newx][newy]++;
                                dist[newx][newy] += d + 1;
                                visit[newx][newy] = true;
                                q.push({newx, newy, d + 1});
                            }
                        }
                    }
                }
            }
       }
       int res = INT_MAX;
       for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && count[i][j] == building) {
                    res = min(res, dist[i][j]);
                }
            }
       }
       return res == INT_MAX ? -1 : res;
    }
};
