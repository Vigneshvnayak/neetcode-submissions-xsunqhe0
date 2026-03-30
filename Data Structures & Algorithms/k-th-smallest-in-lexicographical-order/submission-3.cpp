class Solution {
public:
    int count(long long c, int n) {
        long long cur = c;
        long long nei = cur + 1;
        long long res = 0;
        while (cur <= n) {
            res += min(nei, (long long) n + 1) - cur;
            cur *= 10;
            nei *= 10;
        }
        return res;
    }
    int findKthNumber(int n, int k) {
       long long i = 1;
       long long cur = 1;
       while (i < k) {
            long long step = count(cur, n);
            if (i + step <= k) {
                cur++;
                i += step;
            } else {
                cur *= 10;
                i++;
            }
       }
       return (int) cur;
    }
};