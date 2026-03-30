class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        int m = slots1.size(), n = slots2.size();
        int i = 0, j = 0;
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        while (i < m && j < n) {
            int start = max(slots1[i][0], slots2[j][0]);
            int end = min(slots1[i][1], slots2[j][1]);
            if (slots1[i][1] <= slots2[j][1]) {
                i++;
            } else {
                j++;
            }
            if (start >= end) {
                continue;
            }
            if (end - start >= duration) {
                return {start, start + duration};
            }
        }
        return {};
    }
};
