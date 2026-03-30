class Solution {
public:
    int count(int c, int n) {
        int cur = c;
        int nei = cur + 1;
        int res = 0;
        while (cur <= n) {
            res += min(nei, n + 1) - cur;
            cur *= 10;
            nei *= 10;
        }
        return res;
    }
    int findKthNumber(int n, int k) {
       int i = 1;
       int cur = 1;
       while (i < k) {
            int step = count(cur, n);
            if (i + step <= k) {
                cur++;
                i += step;
            } else {
                cur *= 10;
                i++;
            }
       }
       return cur;
    }
};