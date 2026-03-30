class Solution {
public:
    vector<vector<int>> memo;
    int n1;
    int n2;
    int dfs(int i, int j, string& text1, string& text2) {
       if (i == n1 || j == n2) {
            return 0;
       }
       if (memo[i][j] != -1) {
            return memo[i][j];
       }
       if (text1[i] == text2[j]) {
            memo[i][j] = 1 + dfs(i+1, j+1, text1, text2);
       } else {
            memo[i][j] = max({dfs(i+1, j, text1, text2), dfs(i, j+1, text1, text2)});
       }
       return memo[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        n1 = text1.size();
        n2 = text2.size();
        memo.resize(n1, vector<int>(n2, -1));
        return dfs(0, 0, text1, text2);
    }
};
