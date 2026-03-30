class Solution {
public:
    vector<string> dfs(int i, int n, string s, unordered_set<string>& wd, unordered_map<int, vector<string>>& dp) {
        if (i == n) {
            return {""};
        }
        if (dp.count(i) > 0) {
            return dp[i];
        }
        vector<string> res;
        for (int j = i; j < n; j++) {
            string cur = s.substr(i, j - i + 1);
            if (!wd.count(cur)) {
                continue;
            }
            vector<string> next = dfs(j + 1, n, s, wd, dp);
            for (const string &temp : next) {
                string sentence = cur;
                if (!temp.empty()) {
                    sentence += " " + temp;
                }
                res.push_back(sentence);
            }
        }
        dp[i] = res;
        return res;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> wd(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> dp;
        vector<string> res;
        res = dfs(0, n, s, wd, dp);
        return res;
    }
};