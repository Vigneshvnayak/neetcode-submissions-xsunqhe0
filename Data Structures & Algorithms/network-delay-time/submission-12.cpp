class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> adj;
        for (vector<int>& t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        unordered_set<int> visit;
        pq.push({0, k});
        int res = 0;
        while (!pq.empty()) {
            pair<int,int> cur = pq.top();
            pq.pop();
            int time = cur.first;
            int node = cur.second;
            if (visit.count(node)) {
                continue;
            }
            res = time;
            visit.insert(node);
            for (pair<int,int> next : adj[node]) {
                if (!visit.count(next.first)) {
                    pq.push({time + next.second, next.first});
                }
            }
        }
        return (visit.size() == n) ? res : -1;
    }
};
