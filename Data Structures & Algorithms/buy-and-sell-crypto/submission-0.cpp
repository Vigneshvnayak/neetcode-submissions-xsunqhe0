class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int val = 0;
        while (r < prices.size()) {
            int diff = prices[r] - prices[l];
            if (diff < 0) {
                l++;
            }
            r++;
            val = max(val, diff);
        }
        return val;
    }
};
