class Solution {
public:
    int ROWS;
    int COLS;
    void bfs(queue<pair<int, int>> &q, vector<vector<int>> &v, vector<vector<int>> &h) {
       vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
       while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        int r = cur.first;
        int c = cur.second;
        
        for (vector<int> &d : dir) {
            int nr = r + d[0];
            int nc = c + d[1];
            if (nr >= 0 && nc >=0 && nr < ROWS && nc < COLS &&
             !v[nr][nc] && h[nr][nc] >= h[r][c]) {
                q.push({nr, nc});
                v[nr][nc] = 1;
             }
          }
       }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
       ROWS = heights.size();
       COLS = heights[0].size();
       queue<pair<int, int>> qp;
       queue<pair<int, int>> qa;
       vector<vector<int>> vp(ROWS, vector<int>(COLS, 0));
       vector<vector<int>> va(ROWS, vector<int>(COLS, 0));
       for (int i=0; i<ROWS; i++) {
        qp.push({i, 0});
        vp[i][0] = 1;
        qa.push({i, COLS-1});
        va[i][COLS-1] = 1;
       }
       for (int i=0; i<COLS; i++) {
        qp.push({0, i});
        vp[0][i] = 1;
        qa.push({ROWS-1, i});
        va[ROWS-1][i] = 1;
       }
       bfs(qp, vp, heights);
       bfs(qa, va, heights);
       vector<vector<int>> res;
       for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            if (vp[i][j] & va[i][j]) {
                res.push_back({i, j});
            }
          }
       }
       return res; 
    }
};
