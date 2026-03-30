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
           mp[s[l]]--;
           l++; 
        }
        maxv = max(maxv, r-l+1);
        r++;
       }
       return maxv;
    }
};
