class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        for (vector<int> i : intervals) {
            if (!res.empty() && res.back()[1] >= i[0]) {
                res.back()[1] = max(res.back()[1], i[1]);
            } else {
                res.push_back(i);
            }
        }
        return res;
    }
};
