class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vector<vector<string>> res;
       unordered_map<string, vector<string>> mp;
       for (string s : strs) {
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }
            string key = "";
            for (int i = 0; i < 26; i++) {
                key += "" + ('a' + i) + to_string(count[i]);
            }
            mp[key].push_back(s);
       }
       for (auto [key, value] :  mp) {
            res.push_back(value);
       }
       return res;
    }
};
