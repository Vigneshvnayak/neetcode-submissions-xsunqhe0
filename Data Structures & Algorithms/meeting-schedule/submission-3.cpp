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
    bool canAttendMeetings(vector<Interval>& intervals) {
       sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){
            return a.start < b.end;
       }); 
       int prev_end = intervals[0].end;
       int n = intervals.size();
       for (int i = 1; i < n; i++) {
            if (intervals[i].start < prev_end) {
                return false;
            }
            prev_end = intervals[i].end;
       }
       return true;
    }
};
