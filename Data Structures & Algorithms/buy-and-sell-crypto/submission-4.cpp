class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minv = prices[0];
        int maxv = INT_MIN;
        for (int i = 1; i < prices.size(); i++) {
            int diff = prices[i] - minv;
            maxv = max(maxv, max(diff, 0));
            minv = min(minv, prices[i]);
        }
        return maxv;
    }
};
