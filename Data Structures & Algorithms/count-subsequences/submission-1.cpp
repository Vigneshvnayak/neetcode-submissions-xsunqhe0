class Solution {
public:
    vector<vector<int>> dp;
    int m;
    int n;
    int dfs(int i, int j, string s, string t) {
        if (j == n) {
            return 1;
        }
        if (i == m) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int res = dfs(i + 1, j, s, t);
        if (s[i] == t[j]) {
            res += dfs(i + 1, j + 1, s, t);
        }
        dp[i][j] = res;
        return res;
    }
    int numDistinct(string s, string t) {
       m = s.length();
       n = t.length();
       dp.resize(m, vector<int>(n, -1));
       return dfs(0, 0, s, t);
    }
};
