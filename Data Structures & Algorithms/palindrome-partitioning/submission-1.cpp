class Solution {
public:
    vector<vector<string>> res; 
    int n;
    bool ispalindrome(int l, int r, string s) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
                break;
            }
        }
        return true;
    }
    void dfs(int i, vector<string>& temp, string s) {
        if (i >= s.length()) {
            res.push_back(temp);
            return;
        }
        for (int j = i; j < n; j++) {
            if (ispalindrome(i, j, s)) {
                temp.push_back(s.substr(i, j - i + 1));
                dfs(j + 1, temp, s);
                temp.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
       n = s.length();
       vector<string> temp;
       dfs(0, temp, s);
       return res;
    }
};
