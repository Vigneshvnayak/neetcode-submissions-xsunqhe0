class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> combine;
        for (int i = 0; i < n; i++) {
            combine.push_back({position[i], speed[i]});
        }
        sort(combine.begin(), combine.end());
        vector<double> stk;
        for (int i = n - 1; i >= 0; i--) {
            double time = (double)(target - combine[i].first) / combine[i].second;
            if (stk.empty()) {
                stk.push_back(time);
            } else {
                if (stk.back() < time) {
                    stk.push_back(time);
                }
            }
        }
        return stk.size();
    }
};
