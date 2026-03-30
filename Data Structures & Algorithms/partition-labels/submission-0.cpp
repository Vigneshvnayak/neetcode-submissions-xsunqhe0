class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            if (!mp.count(s[i])) {
                mp[s[i]] = {i, i};
            } else {
                mp[s[i]][1] = i;
            }
        }
        vector<vector<int>> combined;
        for (auto [key, val] : mp) {
            combined.push_back(val);
        }
        sort(combined.begin(), combined.end());
        vector<vector<int>> merged;
        for (vector<int> c : combined) {
            if (!merged.empty() && merged.back()[1] > c[0]) {
                merged.back()[1] = max(merged.back()[1], c[1]);
            } else {
                merged.push_back(c);
            }
        }
        vector<int> res; 
        for (vector<int> m : merged) {
            res.push_back(m[1] - m[0] + 1);
        }
        return res;
    }
};
