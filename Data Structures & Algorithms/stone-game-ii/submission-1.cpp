class Solution {
public:
    int n;
    vector<int> suffix;
    vector<vector<int>> dp;
    int dfs(int i, int M, vector<int>& piles) {
        if (i >= n) return 0;
        if (2 * M >= n - i) return suffix[i];
        if (dp[i][M] != -1) return dp[i][M];
        int res = 0;
        for (int x = 1; x <= 2 * M; x++) {
            int opponent = dfs(i + x, max(M, x), piles);
            res = max(res, suffix[i] - opponent);
        }
        return dp[i][M] = res;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        suffix.resize(n + 1, 0);
        dp.resize(n, vector<int>(n + 1, -1));
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }
        return dfs(0, 1, piles);
    }
};