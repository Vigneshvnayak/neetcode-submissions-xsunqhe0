class Solution {
public:
    void dfs(int m, int n, queue<pair<int,int>>& q, vector<vector<int>>& heights, vector<vector<int>>& visit) {
        vector<int> dir = {0, 1, 0, -1, 0};
        while(!q.empty()) {
            pair<int,int> cur = q.front();
            q.pop();
            int i = cur.first;
            int j = cur.second;
            for (int k = 0; k < 4; k++) {
                int newi = i + dir[k];
                int newj = j + dir[k + 1];
                if (newi < 0 || newj < 0 || newi >= m || newj >= n || 
                heights[newi][newj] < heights[i][j] || visit[newi][newj]) {
                    continue;
                }
                visit[newi][newj] = 1;
                q.push({newi, newj});
            }
        }
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        queue<pair<int,int>> pac, atl;
        vector<vector<int>> pacvisit(m, vector<int>(n, 0));
        vector<vector<int>> atlvisit(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            pac.push({i, 0});
            pacvisit[i][0] = 1;
            atl.push({i, n - 1});
            atlvisit[i][n - 1] = 1;
        }
        for (int i = 0; i < n; i++) {
            pac.push({0, i});
            pacvisit[0][i] = 1;
            atl.push({m - 1, i});
            atlvisit[m - 1][i] = 1;
        }
        vector<vector<int>> count(m, vector<int>(n, 0));
        dfs(m, n, pac, heights, pacvisit);
        dfs(m, n, atl, heights, atlvisit);
        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacvisit[i][j] & atlvisit[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
