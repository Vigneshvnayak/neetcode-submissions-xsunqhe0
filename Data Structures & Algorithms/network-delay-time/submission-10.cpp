class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (vector<int> t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_set<int> visit;
        int res = 0;
        pq.push({0, k});
        while (!pq.empty()) {
            pair<int, int> cur = pq.top();
            int time = cur.first;
            int node = cur.second;
            pq.pop();
            if (visit.count(node)) {
                continue;
            }
            res = time;
            visit.insert(node);
            for (pair<int, int> nei : adj[node]) {
                int neinode = nei.first;
                int neitime = nei.second;
                if (!visit.count(neinode)) {
                    pq.push({neitime + time, neinode});
                }
            }
        }
        return (visit.size() == n) ? res : -1;
    }
};
