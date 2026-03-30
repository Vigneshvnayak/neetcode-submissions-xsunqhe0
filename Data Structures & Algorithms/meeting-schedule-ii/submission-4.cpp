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
       int n = intervals.size();
       if (n == 0) return 0;
       int res = 0;
       priority_queue<int, vector<int>, greater<int>> pq;
       sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
       });
       pq.push(intervals[0].end);
       res = 1;
       for (int i = 1; i < n; i++) {
            while (pq.top() <= intervals[i].start) {
                pq.pop();
            }
            pq.push(intervals[i].end);
            res = max(res, static_cast<int>(pq.size()));
       }
       return res;
    }
};
