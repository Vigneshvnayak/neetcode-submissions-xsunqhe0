class Solution {
public:
    int n;
    vector<string> dtos = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;

    void dfs(int index, string cur, string& digits) {
        if (index == digits.length()) {
            res.push_back(cur);
            return;
        }
        string str = dtos[digits[index] - '0'];
        for (char c : str) {
            dfs(index + 1, cur + c, digits);
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        if (!digits.length()) return {};
        dfs(0, "", digits);
        return res;
    }
};
