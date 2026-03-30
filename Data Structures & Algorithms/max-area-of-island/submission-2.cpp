class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       int max_area = 0;
       queue<vector<int>> q;
       vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
       int r = grid.size();
       int c = grid[0].size();
       for (int i=0; i < r; i++) {
            for (int j=0; j < c; j++) {
                int area = 0;
                if (grid[i][j]) {
                    q.push({i, j});
                    while (q.size()) {
                        vector<int> t = q.front();
                        q.pop();  
                        if (min(t[0],t[1]) < 0 || t[0] >= r || t[1] >= c || !grid[t[0]][t[1]]) {
                            continue;
                        }
                        grid[t[0]][t[1]] = 0;
                        area++;
                        for (vector<int> d : dir) {
                            int new_i = t[0] + d[0];
                            int new_j = t[1] + d[1];
                            q.push({new_i, new_j});
                        }
                    }
                }
                max_area = max(max_area, area);
            }
       }
       return max_area;
    }
};
