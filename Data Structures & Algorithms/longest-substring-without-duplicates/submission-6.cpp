class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char, int> mp;
	   int l = 0;
       int res = INT_MIN;
	   for (int r = 0; r < s.size(); r++) {
		   ++mp[s[r]];
		   while (mp[s[r]] > 1) {
              --mp[s[l]];
              l++; 
           }
           res = max(res, r - l + 1);
       }
       return res;
    }
};
