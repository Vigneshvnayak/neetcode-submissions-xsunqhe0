class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int base = 0, extra = 0, sum = 0;
        int l = 0, n = customers.size();
        for (int r = 0; r < n; r++) {
            if (!grumpy[r]) base += customers[r];
            if (grumpy[r]) sum += customers[r];
            if (r - l + 1 > minutes) {
                if (grumpy[l]) sum -= customers[l];
                l++;
            }
            extra = max(extra, sum);
        }
        return base + extra;
    }
};