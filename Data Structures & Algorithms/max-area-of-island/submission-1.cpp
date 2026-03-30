class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       int area = 0;
       int m = grid.size();
       int n = grid[0].size();
       stack<pair<int,int>> s;
       for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            int count = 0;
            if (grid[i][j] == 1) {
                s.push({i, j});
                while (!s.empty()) {
                    pair<int, int> c = s.top();
                    s.pop();
                    int ni = c.first;
                    int nj = c.second;
                    if (min(ni, nj) < 0 || ni >= m || nj >= n ||
                     grid[ni][nj] == 0) {
                        continue;
                     }
                     count++;
                     grid[ni][nj] = 0;
                     s.push({ni+1, nj});
                     s.push({ni-1, nj});
                     s.push({ni, nj+1});
                     s.push({ni, nj-1});
                }
                area = max(area, count);
            }
        }
       }
       return area;
    }
};
