/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
       vector<Interval> event;
       for (vector<Interval> s : schedule) {
            for (Interval i : s) {
                event.push_back(i);
            }
       }
       sort(event.begin(), event.end(), [](const Interval &a, const Interval &b){
            return a.start < b.start;
       });
       int end = event[0].end;
       vector<Interval> res;
       for (int i = 1; i < event.size(); i++) {
            if (end < event[i].start) {
                Interval t(end, event[i].start);
                res.push_back(t);
                end = event[i].end;
            } else {
                end = max(end, event[i].end);
            }
       }
       return res;
    }
};
