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
        if (!intervals.size()) return 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
        int res = 1;
        for (Interval i : intervals) {
            if (pq.empty()) {
                pq.push(i.end);
            } else {
                while (!pq.empty() && pq.top() <= i.start) {
                    pq.pop();
                }
                pq.push(i.end);
                res = max(res, (int) pq.size());
            }
        }
        return res;
    }
};
