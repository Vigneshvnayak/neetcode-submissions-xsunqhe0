/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> st;
        vector<int> et;
        for (int i=0; i<intervals.size(); i++) {
            st.push_back(intervals[i].start);
            et.push_back(intervals[i].end);
        }
        sort(st.begin(), st.end());
        sort(et.begin(), et.end());
        int i =0, j = 0;
        int c = 0;
        while (i < intervals.size()) {
            if (st[i] <= et[j]) {
                c += 1;
                i++;
            } else {
                c -= 1;
                j++;
            }
        }
        return c;
    }
};
