class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> row_count(rows, 0);
        vector<int> col_count(cols, 0);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j]) {
                    row_count[i]++;
                    col_count[j]++;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] && max(row_count[i], col_count[j]) > 1) {
                    res++;
                }
            }
        }
        return res;
    }
};