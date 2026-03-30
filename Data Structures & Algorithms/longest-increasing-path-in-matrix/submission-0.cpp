class Solution {
    vector<vector<int>> dp;
    vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1, 0}};
public:
    int dfs(int i, int j, vector<vector<int>>& matrix, int prev) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (i >= m || i < 0 || j >= n || j < 0 || matrix[i][j] <= prev) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int res = 1;
        for (vector<int> d : dir) {
            int ni = i + d[0];
            int nj = j + d[1];
            res = max(res, 1 + dfs(ni, nj, matrix, matrix[i][j]));
        }
        dp[i][j] = res;
        return res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
       int m = matrix.size();
       int n = matrix[0].size();
       dp.assign(m, vector<int>(n, -1));
       int res = INT_MIN;
       for (int i=0; i < m; i++) {
        for (int j=0; j < n; j++) {
           res = max(res, dfs(i, j, matrix, INT_MIN));
        }
       }
       return res;
    }
};
