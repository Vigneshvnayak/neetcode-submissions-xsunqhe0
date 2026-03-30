class Solution {
public:
    int sum_square(int n) {
        int sum = 0;
        while (n != 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = sum_square(n);
        while (fast != slow) {
            fast = sum_square(fast);
            fast = sum_square(fast);
            slow = sum_square(slow);
        }
        return fast == 1;
    }
};
