class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        priority_queue<int, vector<int>, greater<int>> available;
        vector<int> count(n, 0);
        sort(meetings.begin(), meetings.end());
        for (int i = 0; i < n; i++) {
            available.push(i);
        }
        for (vector<int> m : meetings) {
            while (!pq.empty() && pq.top()[0] <= m[0]) {
                vector<int> t = pq.top();
                pq.pop();
                available.push(t[1]);
            }
            if (!available.empty()) {
                int free = available.top();
                available.pop();
                pq.push({m[1], free});
                count[free]++;
            } else {
                vector<int> t = pq.top();
                pq.pop();
                int duration = m[1] - m[0];
                pq.push({t[0] + duration, t[1]});
                count[t[1]]++;
            }
        }
        int res = 0, maxc = 0;
        for (int i = 0; i < n; i++) {
            if (maxc < count[i]) {
                maxc = count[i];
                res = i;
            }
        }
        return res;
    }
};