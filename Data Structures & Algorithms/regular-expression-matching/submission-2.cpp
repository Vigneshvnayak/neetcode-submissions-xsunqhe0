class Solution {
public:
    vector<vector<int>> dp;
    int n, m;

    bool dfs(int i, int j, string& s, string& p) {
        if (j == m) {
            return i == n;
        }
        if (dp[i][j] != -1) {
            return dp[i][j] == 1;
        }

        bool match = i < n && (s[i] == p[j] || p[j] == '.');

        if (j + 1 < m && p[j + 1] == '*') {
            dp[i][j] = (dfs(i, j + 2, s, p) || (match && dfs(i + 1, j, s, p))) ? 1 : 0;
        } else {
            dp[i][j] = (match && dfs(i + 1, j + 1, s, p)) ? 1 : 0;
        }
        
        return dp[i][j] == 1;
    }

    bool isMatch(string s, string p) {
        n = s.length();
        m = p.length();
        dp.assign(n + 1, vector<int>(m + 1, -1));
        return dfs(0, 0, s, p);
    }
};