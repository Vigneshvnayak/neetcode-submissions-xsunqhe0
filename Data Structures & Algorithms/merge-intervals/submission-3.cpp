class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for (vector<int> i : intervals) {
            if (res.empty()) {
                res.push_back(i);
            } else {
                int back = res.back()[1];
                if (i[0] <= back) {
                    res.back()[1] = max(back, i[1]);
                } else {
                    res.push_back(i);
                }
            } 
        }
        return res;
    }
};
