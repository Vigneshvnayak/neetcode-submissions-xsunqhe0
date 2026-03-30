class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int l = 0;
       unordered_map<char, int> mp;
       int res = 0;
       for (int r = 0; r < s.length(); r++) {
            mp[s[r]]++;
            while (mp[s[r]] > 1)  {
                mp[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
       }
       return res;
    }
};
