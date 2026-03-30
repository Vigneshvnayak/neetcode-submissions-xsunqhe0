class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
       int m = grid.size(); 
       int n = grid[0].size();
       priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
       vector<vector<bool>> visited(m, vector<bool>(n, false));
       vector<int> dir = {0, 1, 0};
       pq.push({grid[0][0], 0, 0});
       while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int sum = cur[0];
            if (cur[1] == m-1 && cur[2] == n-1) {
                return sum;
            }
            visited[cur[1]][cur[2]] = true;
            for (int i=0; i < 2; i++) {
                int ni = cur[1] + dir[i];
                int nj = cur[2] + dir[i+1];
                if (ni < m && nj < n && !visited[ni][nj]) {
                    pq.push({sum + grid[ni][nj], ni, nj});
                }
            }
       }
       return -1;
    }
};