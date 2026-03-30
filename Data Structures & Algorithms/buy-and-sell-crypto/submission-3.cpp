class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int minv = prices[0];
       int maxv = 0;
       for (int i=0; i<prices.size(); i++) {
        int diff = prices[i] - minv;
        maxv = max(maxv, diff);
        minv = min(minv, prices[i]);
       }
       return maxv;
    }
};
