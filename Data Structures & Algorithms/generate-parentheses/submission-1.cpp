class Solution {
public:
    vector<string> res;
    void dfs(int open, int close, int n, string s) {
        if (open == n && close == n) {
            res.push_back(s);
            return;
        }
        if (open < n) {
            dfs(open + 1, close, n, s + '(');
        }
        if (open > close && close < n) {
            dfs(open, close + 1, n, s + ')');
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        int open = 0, close = 0;
        dfs(open, close, n, "");
        return res;
    }
};
