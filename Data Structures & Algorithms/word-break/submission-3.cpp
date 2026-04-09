class Solution {
public:
    int w = 0; 
    vector<int> dp;
    bool dfs(int i, string s, unordered_set<string>& wordDict) {
        if (i == s.length()) return true;
        if (dp[i] != -1) return dp[i];
        for(int j = i; j < min(i + w, (int)s.length()); j++) {
            string temp = s.substr(i, j - i + 1);
            if (wordDict.count(temp) > 0) {
                if (dfs(j + 1, s, wordDict)) {
                    dp[i] = 1;
                    return true;
                }
            }
        }
        dp[i] = 0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordDictSet;
        wordDictSet.insert(wordDict.begin(), wordDict.end());
        dp.resize(s.length(), -1);
        for (string word : wordDict) {
            w = max(w, (int) word.length());
        }
        return dfs(0, s, wordDictSet);
    }
};
