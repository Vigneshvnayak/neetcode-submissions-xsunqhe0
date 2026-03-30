class Solution {
public:
    int num_square(int n) {
        int res = 0;
        while (n) {
            int rem = n % 10;
            res = res + pow(rem, 2);
            n = n / 10;
        }
        return res;
    }
    bool isHappy(int n) {
       int slow = n, fast = n; 
       while (true) {
            slow = num_square(slow);
            fast = num_square(fast);
            fast = num_square(fast);
            if (slow == fast) {
                break;
            }
       }
       return (slow == 1) ? true : false;
    }
};
