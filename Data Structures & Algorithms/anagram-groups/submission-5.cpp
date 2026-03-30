class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;
        for (string &s : strs) {
            vector<int> a(26, 0);
            for (char &c : s) {
                a[c - 'a']++;
            }
            string temp = "";
            for (int i = 0; i < 26; i++) {
                temp += static_cast<char>('a' + i) + to_string(a[i]);
            }
            mp[temp].push_back(s);
        }
        for (auto [key, value] : mp) {
            res.push_back(value);
        }
        return res;
    }
};
