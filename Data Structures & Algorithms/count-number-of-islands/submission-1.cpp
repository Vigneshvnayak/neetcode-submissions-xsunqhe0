class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        stack<pair<int, int>> s;
        int m = grid.size();
        int n = grid[0].size();
        for (int i=0; i < m; i++) {
            for (int j=0; j < n; j++) {
                if (grid[i][j] == '1') {
                    s.push({i, j});
                    count++;
                    while (!s.empty()) {
                        pair<int, int> c = s.top();
                        s.pop();
                        int ni = c.first;
                        int nj = c.second;
                        if (min(ni, nj) < 0 || ni >= m || nj >= n || grid[ni][nj] == '0') {
                            continue;
                        }
                        grid[ni][nj] = '0';
                        s.push({ni+1, nj});
                        s.push({ni-1, nj});
                        s.push({ni, nj+1});
                        s.push({ni, nj-1});
                        
                    }
                }
            }
        }
        return count;
    }
};
