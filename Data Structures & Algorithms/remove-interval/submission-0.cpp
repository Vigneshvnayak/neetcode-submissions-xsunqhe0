class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> res;
        for (vector<int> i : intervals) {
            if (i[1] < toBeRemoved[0] || i[0] > toBeRemoved[1]) {
                res.push_back(i);
                continue;
            }
            vector<int> t = i;
            if (toBeRemoved[0] > t[0] && toBeRemoved[0] < t[1]) {
                res.push_back({t[0], toBeRemoved[0]});
            }
            if (toBeRemoved[1] > t[0] && toBeRemoved[1] < t[1]) {
                res.push_back({toBeRemoved[1], t[1]});
            }
        }
        return res;
    }
};
