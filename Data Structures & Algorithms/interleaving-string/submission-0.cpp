class Solution {
public:
    vector<vector<int>> dp;
    bool isInterleave(string s1, string s2, string s3) {
       dp = vector<vector<int>>(s1.length() + 1, vector<int> (s2.length() + 1, -1));
       return dfs(0, 0, s1, s2, s3);
    }
    bool dfs(int i, int j, string s1, string s2, string s3) {
        if (i + j >= s3.length()) {
            return (i == s1.length()) && (j == s2.length());
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int res = 0;
        if (i < s1.length() && s1[i] == s3[i+j]) {
            res = dfs(i+1, j, s1, s2, s3);
        }
        if (res != 1 && j < s2.length() && s2[j] == s3[i+j]) {
            res = dfs(i, j+1, s1, s2, s3);
        }
        dp[i][j] = res;
        return dp[i][j];
    }
};
