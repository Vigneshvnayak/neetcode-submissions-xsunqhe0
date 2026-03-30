class Solution {
public:
    void dfs(int open, int close, int n, string s, vector<string>& res) {
        if (open == n && close == n) {
            res.push_back(s);
        }

        if (open < n) {
            dfs(open + 1, close, n, s + '(', res);
        }
        if (close < n && close < open) {
            dfs(open, close + 1, n, s + ')', res);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
       vector<string> res; 
       dfs(0, 0, n, "", res);
       return res;
    }
};
