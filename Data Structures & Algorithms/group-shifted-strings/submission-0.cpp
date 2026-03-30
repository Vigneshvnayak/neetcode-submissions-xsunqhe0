class Solution {
public:
    string get_hashkey(string s) {
        string hashkey;
        for (int i = 1; i < s.length(); i++) {
            hashkey += (s[i] - s[i - 1] + 26) % 26 + 'a';
        }
        return hashkey;
    }
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for (string str : strings) {
            string hashkey = get_hashkey(str);
            mp[hashkey].push_back(str);
        }
        for (auto [k, v] : mp) {
            res.push_back(v);
        }
        return res;
    }
};
