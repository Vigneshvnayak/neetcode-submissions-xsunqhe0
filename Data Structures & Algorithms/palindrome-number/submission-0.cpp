class Solution {
public:
    bool isPalindrome(int x) {
       string temp = to_string(x);
       int l = 0, r = temp.length() - 1;
       while (l < r) {
            if (!(temp[l++] == temp[r--])) {
                return false;
            }
       }
       return true;
    }
};