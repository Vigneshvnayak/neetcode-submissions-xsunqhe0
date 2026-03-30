class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
       int sum = 0;
       for (int b : bills) {
            int temp = 0;
            sum += 5;
            if (b > 5) {
                temp = b - 5;
                sum -= temp;
            }
            if (sum < 0) {
                return false;
            }
       }
       return true;
    }
};