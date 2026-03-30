class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (vector<int> t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_set<int> visit;
        pq.push({0, k});
        while (!pq.empty()) {
            pair<int, int> cur = pq.top();
            pq.pop();
            visit.insert(cur.second);
            if (visit.size() == n) {
                return cur.first;
            }
            for (pair<int, int> nei : adj[cur.second]) {
                int node = nei.first;
                int time = nei.second;
                if (!visit.count(node)) {
                    pq.push({cur.first + time, node});
                }
            }
        }
        return -1;
    }
};
