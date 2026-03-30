class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        char max_freq = 0;
        int res = 0;
        int l = 0;
        int r = 0;
        unordered_map<char, int> mp;
        for (r < s.length()) {
            mp[s[r]]++;
            max_freq = max(max_freq, mp[s[r]]);
            while ((r - l + 1) - mp[max_char] > k) {
                mp[s[l]]--;
                max_freq = max(max_freq, mp[s[l]]);
                l++;
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};
