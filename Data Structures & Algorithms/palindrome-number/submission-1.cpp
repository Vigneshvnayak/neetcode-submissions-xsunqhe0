class Solution {
public:
    bool isPalindrome(int x) {
       int temp = x;
       int res = 0; 
       while (temp > 0) {
            res = res * 10 + temp % 10;
            temp /= 10;
       }
       return (x == res) ? true : false;
    }
};