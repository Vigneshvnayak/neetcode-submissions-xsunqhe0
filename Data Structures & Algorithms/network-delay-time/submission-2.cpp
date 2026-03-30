class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, vector<pair<int,int>>> adj;
        for (int i=1; i<n+1; i++) {
            adj[i] = vector<pair<int,int>>();
        }
        for (vector<int> t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }
        unordered_set<int> visit;
        pq.push({0, k});
        int t = 0;
        while (!pq.empty()) {
            pair<int, int> c = pq.top();
            pq.pop();
            int w = c.first;
            int d = c.second;
            if (visit.count(d) > 0) {
                continue;
            }
            visit.insert(d);
            t = w;
            for (pair<int, int> a : adj[d]) {
                if (visit.count(a.first) == 0) {
                    pq.push({w + a.second, a.first});
                } 
            }
        }
        return visit.size() == n ? t : -1;

    }
};
