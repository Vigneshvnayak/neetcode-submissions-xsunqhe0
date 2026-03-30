class Solution {
public:
    void palindrome(int i, int j, string s, string &temp) {
        int n = s.length();
        while (i >=0 && j < n) {
            if(s[i] == s[j]) {
                temp = s.substr(i, j - i + 1);
                i--;
                j++;
            } else {
                break;
            }
        }
        if (temp.empty()) {
            temp = s[i];
        }
    }
    string longestPalindrome(string s) {
       string res = "";
       for (int i = 0; i < s.length(); i++) {
            string p1 = "";
            string p2 = "";
            palindrome(i, i, s, p1);
            palindrome(i, i + 1, s, p2);
            if (res.length() < p1.length()) {
                res = p1;
            }
            if (res.length() < p2.length()) {
                res = p2;
            }  
       }
       return res;
    }
};
