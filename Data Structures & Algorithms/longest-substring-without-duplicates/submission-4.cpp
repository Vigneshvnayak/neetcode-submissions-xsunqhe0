class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char, int> mp;
       int maxv = 0;
       int l = 0;
       int r = 0;
       while (r < s.size()) {
        mp[s[r]]++;
        while (mp[s[r]] > 1) {
           maxv = max(maxv, r-l);
           mp[s[l]]--;
           l++; 
        }
        r++;
       }
       maxv = max(maxv, r-l);
       return maxv;
    }
};
