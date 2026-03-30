class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
       int l = INT_MAX;
       int r = INT_MIN;
       for (vector<int> t : trips) {
            l = min(l, t[1]);
            r = max(r, t[2]);
       }
       vector<int> prefix(r - l + 2, 0);
       for (vector<int> t : trips) {
            prefix[t[1] - l] += t[0];
            prefix[t[2] - l] -= t[0];
       }
       int sum = 0;
       for (int i = 0; i < prefix.size(); i++) {
            sum += prefix[i];
            if (sum > capacity) {
                return false;
            }
       }
       return true;
    }
};