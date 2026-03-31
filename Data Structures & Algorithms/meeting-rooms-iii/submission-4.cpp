class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> rooms(n, 0);
        priority_queue<int, vector<int>, greater<int>> available;
        sort(meetings.begin(), meetings.end());
        for (int i = 0; i < n; i++) {
            available.push(i);
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> busy;
        for (vector<int> m : meetings) {
            while (!busy.empty() && busy.top()[0] <= m[0]) {
                available.push(busy.top()[1]);
                busy.pop();
            }
            if (!available.empty()) {
                int free = available.top();
                available.pop();
                rooms[free]++;
                busy.push({m[1], free});
            } else {
                vector<int> wait = busy.top();
                busy.pop();
                int duration = m[1] - m[0];
                rooms[wait[1]]++;
                busy.push({wait[0] + duration, wait[1]});
            }
        }
        int res = n, count = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (count < rooms[i]) {
                res = i;
                count = rooms[i];
            }
        }
        return res;
    }
};