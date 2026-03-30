class Solution {
public:
    unordered_map<int, bool> memo;
    bool wordBreak(string s, vector<string>& wordDict) {
       memo[s.size()] = true;
       return dfs(0, s, wordDict);
    }
    bool dfs(int index, string s, vector<string> word_dict) {
        if (memo.count(index) > 0) {
            return memo[index];
        }
        for (string w : word_dict) {
            if (index + w.length() <= s.length() && 
                s.substr(index, w.length()) == w) {
                    if (dfs(index + w.length(), s, word_dict)) {
                        memo[index] = true;
                        return true;
                    }
                }
        }
        return memo[index] = false;
        
    }
};
