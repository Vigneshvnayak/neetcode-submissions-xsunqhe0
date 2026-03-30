class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int m = grid.size();
        int n = grid[0].size();
        pq.push({grid[0][0], 0, 0});
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        int time;
        while (!pq.empty()) {
            vector<int> c = pq.top();
            pq.pop();
            time = c[0];
            int i = c[1];
            int j = c[2];
            if (i == m-1 && j == n-1) {
                return time;
            }
            if (visit[i][j]) {
                continue;
            }
            visit[i][j] = true;
            for (vector<int>& d : dir) {
                int newi = i + d[0];
                int newj = j + d[1];
                if (newi >= 0 && newj >= 0 && newi < m && newj < n) {
                    pq.push({max(grid[newi][newj], time), newi, newj});
                }
            }   
        }
        return m * n;
    }
};
