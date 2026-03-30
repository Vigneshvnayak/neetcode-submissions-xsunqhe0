class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       vector<int> a(amount+1, INT_MAX);
       a[amount] = 0;
       for (long i=amount-1; i>=0; i--) {
        for (int c : coins) {
            if (i + c <= amount && a[i+c] != INT_MAX) {
                    a[i] = min(a[i], a[i+c] + 1);
                }
            }
         }
       if(a[0] == INT_MAX) {
        return -1;
       }
       return a[0];
    }
};
