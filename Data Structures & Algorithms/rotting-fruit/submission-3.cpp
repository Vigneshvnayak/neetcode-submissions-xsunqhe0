class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       int fresh = 0;
       int rows = grid.size();
       int cols = grid[0].size();
       queue<pair<int, int>> q;
       for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            if (grid[i][j] == 1) {
                fresh++;
            }
            if (grid[i][j] == 2) {
                q.push({i, j});
            }
        }
       }
       vector<vector<int>> dir = {{0,1} ,{0,-1}, {1,0}, {-1, 0}};
       int res = 0;
       while (fresh > 0 && !q.empty()) {
        int size = q.size();
        for (int k=0; k < size; k++) {
            pair<int, int> cur = q.front();
            q.pop();
            int i = cur.first;
            int j = cur.second;
            for (vector<int> d : dir) {
                int ni = i + d[0];
                int nj = j + d[1];
                if (ni >= 0 && nj >= 0 && ni < rows && nj < cols && 
                    grid[ni][nj] == 1) {
                        grid[ni][nj] = 2;
                        q.push({ni, nj});
                        fresh--;
                    }
                }
            }   
            res++;
        }
        return (fresh == 0)? res : -1;
    }
};
