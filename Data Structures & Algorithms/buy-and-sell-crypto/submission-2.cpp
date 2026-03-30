class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;  // Left pointer (buy point)
        int r = 1;  // Right pointer (sell point)
        int val = 0;  // Maximum profit

        while (r < prices.size()) {
            int diff = prices[r] - prices[l];
            if (diff > 0) {
                val = max(val, diff);  // Update max profit if selling at r is better
            } else {
                l = r;  // Reset left pointer to current right pointer if price at r is lower than price at l
            }
            r++;  // Move right pointer forward
        }
        return val;  // Return the maximum profit found
    }
};
