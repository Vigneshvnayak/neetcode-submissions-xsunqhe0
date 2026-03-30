class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
       vector<int> dp;
       sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[0] == b[0]) ? b[1] > a[1] : a[0] < b[0];
       });
       for (vector<int> e : envelopes) {
            int h = e[1];
            auto it = lower_bound(dp.begin(), dp.end(), h);
            if (it == dp.end()) {
                dp.push_back(h);
            } else {
                *it = h;
            }
       }
       return dp.size();
    }
};