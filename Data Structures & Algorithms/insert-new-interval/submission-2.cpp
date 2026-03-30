class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for (vector<int> i : intervals) {
            if (res.empty()) {
                res.push_back(i);
            } else {
                int back = res.back()[1];
                if (i[0] <= back) {
                    res.back()[1] = max(i[1], back);
                } else {
                    res.push_back(i);
                }
            }
        }
        return res;
    }
};
