class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        char max_char = s[0];
        int res = 0;
        int l = 0;
        unordered_map<char, int> mp;
        mp[s[0]] = 1;
        for (int r = 1; r < n; r++) {
            mp[s[r]]++;
            if (mp[s[r]] > mp[max_char]) {
                max_char = s[r];
            }
            while ((r - l + 1) - mp[max_char] > k) {
                mp[s[l]]--;
                l++;
                if (mp[s[l]] > mp[max_char]) {
                    max_char = s[l];
                }
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
