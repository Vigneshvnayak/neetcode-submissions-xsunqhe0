class Solution {
public:
    vector<int> dp;
    int n;
    int dfs(int i, vector<int>& days, vector<int>& costs) {
       if (i == n) return 0;
       if (dp[i] != -1) return dp[i];
       int idx = 0, j = i;
       int res = INT_MAX;
       for (int d : {1, 7, 30}) {
            while (j < n && days[j] < days[i] + d) {
                j++;
            }
            res = min(res, costs[idx] + dfs(j, days, costs));
            j = i;
            idx++;
       }
       dp[i] = res;
       return dp[i];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();
        dp.resize(n, -1);
        return dfs(0, days, costs);
    }
};