class Solution {
public:
    int characterReplacement(string s, int k) {
       int res = 0;
       int l = 0;
       int r = 0;
       int maxv = 0;
       unordered_map<char, int> mp;
       while (r < s.length()) {
            mp[s[r]]++;
            maxv = max(maxv, mp[s[r]]);
            while ((r - l + 1) - maxv > k) {
                mp[s[l]]--;
                maxv = max(maxv, mp[s[l]]);
                l++;
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};
