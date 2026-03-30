class Solution {
public:
    int mr;
    int mc;
    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& visit) {
        if(min(r,c) < 0 || r == mr || c == mc || grid[r][c] == 0 || visit[r][c]) {
            return 0;
        }
        visit[r][c] = 1;
        int count = 0;
        count += dfs(r+1, c, grid, visit);
        count +=  dfs(r-1, c, grid, visit);
        count += dfs(r, c+1, grid, visit);
        count += dfs(r, c-1, grid, visit);
        return count + 1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        mr = grid.size();
        mc = grid[0].size();
        int res = 0;
        vector<vector<int>> visit(mr, vector<int>(mc,0));
        for (int i=0; i<mr; i++) {
            for (int j=0; j<mc; j++) {
                if (grid[i][j] == 1) {
                    res= max(res, dfs(i, j, grid, visit));
                }
            }
        }
        return res;
    }
};
