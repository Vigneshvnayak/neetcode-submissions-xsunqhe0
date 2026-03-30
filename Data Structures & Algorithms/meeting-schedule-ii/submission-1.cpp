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
        if (intervals.size() == 0) return 0;
        priority_queue<int, vector<int> , greater<int>> mh;
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a.start < b.start;
        });
        int prev = intervals[0].end;
        int day = 1;
        for (int i=1; i<intervals.size(); i++) {
            if (intervals[i].start < prev) {
                day++;
                mh.push(max(intervals[i-1].end, intervals[i].end));
                prev = min(intervals[i-1].end, intervals[i].end);
            } else {
                prev = intervals[i].end;
            }
        }
        if (mh.size() >= 2) {
            if (!mh.empty()) {
                int i = mh.top();
                mh.pop();
                int j = mh.top();
                mh.pop();
                if (i != j) {
                    day--;
                }
            }
        } 
        return day;
    }
};
