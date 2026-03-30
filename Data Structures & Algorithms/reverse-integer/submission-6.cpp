class Solution {
public:
    int reverse(int x) {
       int res = 0; 
       while (x) {
            int cur = x % 10;
            if (res > INT_MAX / 10 || (res == INT_MAX / 10) && 
                cur > INT_MAX % 10) {
                    return 0;
            } else if (res < INT_MIN / 10 || (res == INT_MIN / 10) &&
                cur < INT_MIN % 10) {
                    return 0;
            }
            res = res * 10 + cur;  
            x /= 10;
       }
       return res;
    }
};
