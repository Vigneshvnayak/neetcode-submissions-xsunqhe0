class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<int> prices(n, INT_MAX);
       prices[src] = 0;
       for (int i = 0; i <= k; i++) {
        vector<int> temp = prices;
        for (vector<int> f : flights) {
            int s = f[0];
            int d = f[1];
            int w = f[2];
            if (prices[s] == INT_MAX) {
               continue; 
            }
            if (w + prices[s] < temp[d]) {
                temp[d] = w + prices[s];
            }
            }
            prices = temp;
       }
       return (prices[dst] == INT_MAX) ? -1 : prices[dst];
    }
};
