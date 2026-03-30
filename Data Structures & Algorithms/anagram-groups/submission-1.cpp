class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<int, vector<string>> mp;
       vector<vector<string>> res;
       for (string s : strs) {
        int key = 0;
        for (char c : s) {
            key += (c - 'a') + 1;
        }
        mp[key].push_back(s);
       }
       for (auto const &x : mp) {
        res.push_back(x.second);
       }
       return res;
    }
};
