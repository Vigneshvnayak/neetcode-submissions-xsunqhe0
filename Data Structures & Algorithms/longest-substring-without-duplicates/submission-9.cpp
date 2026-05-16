class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int res = 0, l = 0;
        unordered_map<char, int> mp;
        for (int r = 0; r < n; r++) {
            mp[s[r]]++;
            while (mp[s[r]] > 1) {
                mp[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
