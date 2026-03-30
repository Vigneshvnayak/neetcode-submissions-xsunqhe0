class Solution {
public:
    vector<vector<int>> dp;
    int m;
    int n;
    int dfs(int i, int j, int prev, vector<int>& dir, vector<vector<int>>& matrix) {
        if (i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] <= prev) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int res = 1;
        for (int k = 0; k < 4; k++) {
            int newi = i + dir[k];
            int newj = j + dir[k + 1];
            res = max(res, 1 + dfs(newi, newj, matrix[i][j], dir, matrix));
        }
        dp[i][j] = res;
        return res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
       m = matrix.size();
       n = matrix[0].size();
       dp.resize(m, vector<int>(n, -1));
       vector<int> dir = {0, 1, 0, -1, 0};
       int res = 0;
       for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, dfs(i, j, INT_MIN, dir, matrix));
            }
       }
       return res;
    }
};
