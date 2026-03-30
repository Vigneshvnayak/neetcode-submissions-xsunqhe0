class Solution {
public:
    int palindrome(int l, int r, string s) {
        int count = 0;
        while (l >=0 && r < s.size() && s[l] == s[r]) {
            count++;
            l--;
            r++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int res = 0;
        for (int i=0; i<s.size(); i++) {
            res += (palindrome(i, i+1, s) + palindrome(i, i, s));
        }
        return res;
    }
};
