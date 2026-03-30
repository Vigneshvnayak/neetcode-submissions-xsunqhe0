class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
       int n = INT_MIN;
       for (vector<int> t : trips) {
            n = max(n, t[2]);
       }
       vector<int> prefix(n + 1, 0);
       for (vector<int> t : trips) {
            prefix[t[1]] += t[0];
            prefix[t[2]] += -1 * t[0];
       }
       int sum = 0;
       for (int i = 0; i < n; i++) {
            sum += prefix[i];
            if (sum > capacity) {
                return false;
            }
       }
       return true;
    }
};