class Solution {
public:
    int n;
    vector<vector<string>> res;
    vector<vector<bool>> dp;

    void dfs(int i, vector<string>& temp, string& s) {
        if (i >= n) {
            res.push_back(temp);
            return;
        }
        for (int j = i; j < n; j++) {
            if (dp[i][j]) {
                temp.push_back(s.substr(i, j - i + 1));
                dfs(j + 1, temp, s);
                temp.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
       n = s.length(); 
       dp.resize(n, vector<bool>(n, false));
       for (int i = 0; i < n; i++) {
            dp[i][i] = true;
       }
       for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
            }
       }
       for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                }
            }
       }
       vector<string> temp;
       dfs (0, temp, s);
       return res;
    }
};
