class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int i, int j, int m, int n, string word1, string word2) {
        if (i == m) {
            return n - j;
        }
        if (j == n) {
            return m - i;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (word1[i] == word2[j]) {
            dp[i][j] = dfs(i + 1, j + 1, m, n, word1, word2);
        } else {
            int temp = min(dfs(i + 1, j + 1, m, n, word1, word2),dfs(i + 1, j, m, n, word1, word2));
            temp = min(temp, dfs(i, j + 1, m, n, word1, word2));
            dp[i][j] = temp + 1;
        }
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        dp = vector<vector<int>> (m, vector<int>(n, -1));
        return dfs(0, 0, m, n, word1, word2);
    }
};
