class Solution {
public:
    int climbStairs(int n) {
       vector<int> a(n+1);
       a[n] = 1;
       for (int i=n-1; i>=0; i--) {
        if (i+1 <= n) {
            a[i] += a[i+1];
        }
        if (i+2 <= n) {
            a[i] += a[i+2];
        }
       }
       return a[0];
    }
};
