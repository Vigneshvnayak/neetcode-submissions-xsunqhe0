class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        priority_queue<int> pq;
        for (char t : tasks) {
            mp[t]++;
        }
        for (auto [key, val] : mp) {
            pq.push(val);
        }
        queue<pair<int,int>> q;
        int time = 0;
        while (!pq.empty() || !q.empty()) {
            time++;
            if (pq.empty()) {
                time = q.front().second;
            } else {
                int cnt = pq.top() - 1;
                pq.pop();
                if (cnt > 0) q.push({cnt, time + n});
            }
            if (!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }

        }
        return time;
    }
};
