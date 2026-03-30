class Solution {
public:
    void palindrome(int index, string s, string &temp) {
        int i = index, j = index;
        int n = s.length();
        int max_length = 0;
        while ((i >=0 && j < n) && s[i] == s[j]) {
            if (j - i + 1 > max_length) {
                temp = s.substr(i, j - i + 1);
                max_length = j - i + 1;
            }
            i--;
            j++;
        }
        i = index, j = index + 1;
        while ((i >= 0 && j < n) && s[i] == s[j]) {
            if (j - i + 1 > max_length) {
                temp = s.substr(i, j - i + 1);
                max_length = j - i + 1;
            }
            i--;
            j++;
        }
    }
    string longestPalindrome(string s) {
       string res = "";
       int max_length = 0;
       for (int i = 0; i < s.length(); i++) {
            string p = "";
            palindrome(i, s, p);
            if (max_length < p.length()) {
                res = p;
                max_length = p.length();
            }
       }
       return res;
    }
};
