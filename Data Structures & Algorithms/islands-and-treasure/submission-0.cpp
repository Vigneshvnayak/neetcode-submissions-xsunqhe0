class Solution {
public:
    int INF = 2147483647;
    vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
       queue<pair<int, int>> q;
       int m = grid.size();
       int n = grid[0].size();
       vector<vector<bool>> visit(m, vector<bool>(n, false));
       for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (grid[i][j] == 0) {
                q.push({i,j});
                visit[i][j] = true;
            }
        }
       }
       while (!q.empty()) {
        pair<int, int> c = q.front();
        q.pop();
        int i = c.first;
        int j = c.second;
        int ni = 0;
        int nj = 0;
        for (vector<int> d : dir) {
            ni = i + d[0];
            nj = j + d[1];
          if (min(ni, nj) < 0 || ni >= m || nj >= n || 
          grid[ni][nj] != INF || visit[ni][nj]) {
            continue;
          }
          visit[ni][nj] = true;
          grid[ni][nj] = min(grid[ni][nj], 1 + grid[i][j]);
          q.push({ni, nj});
        }
       }
    }
};
