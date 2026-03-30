class Solution {
public:
    bool isPerfectSquare(int num) {
       int l = 1, r = num;
       while (l <= r) {
            int mid = l + (r - l) / 2;
            int sq = mid * mid;
            if (sq > num) {
                r = mid - 1;
            } else if (sq < num) {
                l = mid + 1;
            } else {
                return true;
            }
       }
       return false;
    }
};