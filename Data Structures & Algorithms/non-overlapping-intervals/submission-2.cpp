class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       int n = intervals.size();
       int res = 0;
       sort(intervals.begin(), intervals.end());
       int prev_end = intervals[0][1];
       for (int i = 1; i < n; i++) {
            if (intervals[i][0] < prev_end) {
                res++;
                prev_end = min(prev_end, intervals[i][1]);
            } else {
                prev_end = intervals[i][1];
            }
       }
       return res;
    }
};
