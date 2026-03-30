class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       int fresh = 0;
       int m = grid.size();
       int n = grid[0].size();
       queue<pair<int,int>> q;
       for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (grid[i][j] == 1) {
                fresh++;
            }
            if (grid[i][j] == 2) {
               q.push({i, j});
            }
        }
       }
       int res = 0;
       vector<vector<int>> dir = {{1,0}, {-1,0}, {0, 1}, {0, -1}};
       while (fresh > 0 && !q.empty()) {
        int size = q.size();
        for (int i=0; i<size; i++) {
           pair<int, int> c = q.front();
           q.pop();
           int row = c.first;
           int col = c.second;
           for(vector<int> d : dir) {
            int ni = row + d[0];
            int nj = col + d[1];
            if (ni >= 0 && nj >= 0 && ni < m && nj < n &&
             grid[ni][nj] == 1) {
                grid[ni][nj] = 2;
                fresh--; 
                q.push({ni, nj});
             }
           }
        }
        res++;
       }
       return (fresh == 0) ? res : -1;
    }
};
