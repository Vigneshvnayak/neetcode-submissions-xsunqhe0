class Solution {
public:
    int reverse(int x) {
       int res = 0;
       while (x != 0) {
            int temp = x % 10;
            x = x / 10;
            if (res > INT_MAX / 10 || (res == INT_MAX && 
                temp > INT_MAX % 10)) {
                    return 0;
            } else if (res < INT_MIN / 10 || (res == INT_MIN &&
                temp < INT_MIN % 10)) {
                    return 0;
                }
           res = res * 10 + temp; 
       }
       return res;
    }
};
