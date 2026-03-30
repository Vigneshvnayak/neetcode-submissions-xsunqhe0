class Solution {
public:
    int mr;
    int mc;
    int dfs(int r, int c, vector<vector<char>>& grid, vector<vector<int>>& visit) {
        if(min(r,c) < 0 || r == mr || c == mc || grid[r][c] == '0' || visit[r][c]) {
            return 0;
        }
        visit[r][c] = 1;
        dfs(r+1, c, grid, visit);
        dfs(r-1, c, grid, visit);
        dfs(r, c+1, grid, visit);
        dfs(r, c-1, grid, visit);
        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        mr = grid.size();
        mc = grid[0].size();
        int count = 0;
        vector<vector<int>> visit(mr, vector<int>(mc,0));
        for (int i=0; i<mr; i++) {
            for (int j=0; j<mc; j++) {
                if (grid[i][j] == '1') {
                    if (dfs(i, j, grid, visit)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
