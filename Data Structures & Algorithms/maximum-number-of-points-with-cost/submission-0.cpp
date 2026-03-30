class Solution {
public:
    int m, n;
    vector<vector<long long>> dp;

    long long dfs(int row, int col, vector<vector<int>>& points) {
        if (row == m) return 0;
        if (dp[row][col] != -1) return dp[row][col];
        long long res = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            res = max(res, points[row][i] - abs(col - i) + dfs(row + 1, i, points));
        }
        dp[row][col] = res;
        return res;
    }
    long long maxPoints(vector<vector<int>>& points) {
       m = points.size();
       n = points[0].size();
       dp.resize(m, vector<long long>(n, -1));
       long long res = LLONG_MIN;
       for (int i = 0; i < n; i++) {
            res = max(res, points[0][i] + dfs(1, i, points));
       }
       return res;
    }
};