class Solution {
public:
    int mr = 0;
    int mc = 0;
    int dfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &visit) {
        if (min(r,c) < 0 || r == mr || c == mc || grid[r][c] || 
            visit[r][c]) {
                return 0;
        }
        if (r == mr-1 && c == mc - 1) {
            return 1;
        }
        visit[r][c] = 1;
        int count = 0;
        count += dfs(r+1, c, grid, visit);
        count += dfs(r-1, c, grid, visit);
        count += dfs(r, c+1, grid, visit);
        count += dfs(r, c-1, grid, visit);
        visit[r][c] = 0;
        return count;
    }
    int countPaths(vector<vector<int>>& grid) {
        mr = grid.size(); 
        mc = grid[0].size();
        vector<vector<int>> visit(mr, vector<int>(mc,0));
        return dfs(0, 0, grid, visit);
    }
};
