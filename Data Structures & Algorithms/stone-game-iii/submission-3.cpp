class Solution {
public:
    vector<vector<int>> memo;
    int n;
    int dfs(int index, int alice, vector<int>& stoneValue) {
        if (index >= n) {
            return 0;
        }
        if (memo[index][alice] != INT_MIN) {
            return memo[index][alice];
        }
        int res = (alice == 0) ? INT_MIN : INT_MAX;
        int score = 0;
        for (int i = index; i < min(index + 3, n); i++){
            if (!alice) {
                score += stoneValue[i];
                res = max(res, score + dfs(i + 1, 1, stoneValue));
            } else {
                score -= stoneValue[i];
                res = min(res, score + dfs(i + 1, 0, stoneValue));
            }
        }
        memo[index][alice] = res;
        return res;
    }
    string stoneGameIII(vector<int>& stoneValue) {
       n = stoneValue.size();
       memo.assign(n, vector<int>(2, INT_MIN));
       int res = dfs(0, 0, stoneValue);
       if (res == 0) {
            return "Tie";
       } else if (res > 0) {
            return "Alice";
       }
       return "Bob";
    }
};