class Solution {
public:
    int num_square(int n) {
        int res = 0;
        while (n > 0) {
            int rem = n % 10;
            res += rem * rem;
            n = n / 10;
        }
        return res;
    }
    bool isHappy(int n) {
       int slow = n, fast = num_square(n); 
       while (slow != fast) {
            slow = num_square(slow);
            fast = num_square(fast);
            fast = num_square(fast);
       }
       return (slow == 1) ? true : false;
    }
};
