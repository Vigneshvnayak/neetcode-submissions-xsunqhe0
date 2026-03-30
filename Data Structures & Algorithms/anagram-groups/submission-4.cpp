class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<int, vector<string>> mp;
       vector<vector<string>> res;
       for (string &s : strs) {
       vector<int> count(26, 0);
        for (char &c : s) {
            count[c - 'a']++;
        }
        int k = 0;
        int l = 1;
        for (int i=0; i < 26; i++) {
            k = l * count[i] + k;
            l = l * 10;
        }
        mp[k].push_back(s);
       }
       for (auto &m : mp) {
         res.push_back(m.second);
       }
       return res;
    }
};
