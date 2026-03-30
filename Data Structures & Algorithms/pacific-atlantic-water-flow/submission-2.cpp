class Solution {
int rows;
int cols;
public:
    void bfs(queue<pair<int,int>> &q, vector<vector<int>> &v,
            vector<vector<int>> &h) {
        vector<vector<int>> dir = {{0, 1}, {0,-1}, {1,0}, {-1,0}};
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            int r = cur.first;
            int c = cur.second;
            for (vector<int> d : dir) {
                int nr = r + d[0];
                int nc = c + d[1];
                if (nr >=0 && nr < rows && nc >=0 && nc < cols &&
                    !v[nr][nc] && h[nr][nc] >= h[r][c]) {
                        v[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();
        vector<vector<int>> vp(rows, vector<int>(cols,0));
        vector<vector<int>> va(rows, vector<int>(cols,0));
        queue<pair<int, int>> qp;
        queue<pair<int, int>> qa;
        for (int i=0; i<rows; i++) {
            vp[i][0] = 1;
            qp.push({i, 0});
            va[i][cols-1] = 1;
            qa.push({i, cols-1});
        }
        for (int i=0; i<cols; i++) {
            vp[0][i] = 1;
            qp.push({0, i});
            va[rows-1][i] = 1;
            qa.push({rows-1, i});
        }
        bfs(qp, vp, heights);
        bfs(qa, va, heights);
        vector<vector<int>> res;
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (va[i][j] & vp[i][j]) {
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};
