class Solution {
public:
    void dfs(int open, int close, int n, string &s, vector<string> &res) {
        if (close == open && open == n) {
            res.push_back(s);
            return;
        }
        if (open < n) {
            s += '(';
            dfs(open + 1, close, n, s, res);
            s.pop_back();
        }
        if (close < open) {
            s += ')';
            dfs(open, close + 1, n, s, res);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string stack;
        dfs(0,0,n,stack,res);
        return res;
    }
};
