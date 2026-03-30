class Solution {
public:
    void palindrome(string s, int l, int r, int &residx,
    int &reslen) {
        while (l >=0 && r < s.size() && s[l] == s[r]) {
            if (r - l + 1 > reslen) {
                reslen = r - l + 1;
                residx = l;
            }
            l--;
            r++;
        }
    }
    string longestPalindrome(string s) {
       int n = s.size();
       int residx = 0;
       int reslen = 0;
       for (int i=0; i<n; i++) {
          palindrome(s, i, i, residx, reslen);
          palindrome(s, i, i+1, residx, reslen);
       }
       return s.substr(residx, reslen);
    }
};
