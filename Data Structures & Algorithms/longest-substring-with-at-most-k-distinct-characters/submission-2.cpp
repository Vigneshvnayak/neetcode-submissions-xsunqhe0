class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
       unordered_map<char, int> mp;
       int l = 0, res = 0;
       for (int r = 0; r < s.length(); r++) {
            mp[s[r]]++;
            while (mp.size() > k) {
                mp[s[l]]--;
                if (mp[s[l]] == 0) {
                    mp.erase(s[l]);
                }
                l++;
            }
            res = max(res, r - l + 1);
       }
       return res;
    }
};
