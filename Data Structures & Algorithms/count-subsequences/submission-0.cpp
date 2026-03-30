class Solution {
    vector<vector<int>> dp;
public:
    int numDistinct(string s, string t) {
       int m = s.length();
       int n = t.length();
       dp.assign(m+1, vector<int>(n+1, -1));
       return dfs(0, 0, s, t, m, n);
    }
    int dfs(int i, int j, string s, string t, int m, int n) {
        if (j == n) {
            return 1;
        }
        if (i == m) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int res = dfs(i+1, j, s, t, m, n);
        if (s[i] == t[j]) {
            res += dfs(i+1, j+1, s, t, m, n);
        }
        dp[i][j] = res;
        return res;
    }
};
