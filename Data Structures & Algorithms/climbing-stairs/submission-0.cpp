class Solution {
public:
    int climbStairs(int n) {
        vector<int> index(n+1, 0);
        index[0] = 1;
        for (int i=1; i<=n; i++) {
            if (i - 1 >= 0) {
                index[i] += index[i-1];
            }
            if (i - 2 >= 0) {
                index[i] += index[i-2];
            }
        }
        return index[n];
    }
};
