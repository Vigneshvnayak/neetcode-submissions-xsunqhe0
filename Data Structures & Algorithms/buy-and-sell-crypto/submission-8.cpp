class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = prices[0];
        int res = 0;
        for (int i = 1; i < n; i++) {
            res = max(res, prices[i] - buy);
            buy = min(buy, prices[i]);
        }
        return res;
    }
};
