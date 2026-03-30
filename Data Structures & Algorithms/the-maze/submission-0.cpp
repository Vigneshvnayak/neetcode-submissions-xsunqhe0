class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest) {
       int m = maze.size();
       int n = maze[0].size();
       queue<pair<int, int>> q; 
       vector<vector<bool>> visit(m, vector<bool>(n, false));
       vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
       q.push({start[0], start[1]});
       visit[start[0]][start[1]] = true;
       while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            if (row == dest[0] && col == dest[1]) {
                return true;
            }
            for (auto d : dir) {
                int r = row;
                int c = col;
                while (r + d[0] >= 0 && r + d[0] < m && c + d[1] >= 0 &&
                    c + d[1] < n && maze[r + d[0]][c + d[1]] == 0) {
                        r += d[0];
                        c += d[1];
                }
                if (!visit[r][c]) {
                    visit[r][c] = true;
                    q.push({r,c});
                }
            }
        }
        return false;
    }
};
