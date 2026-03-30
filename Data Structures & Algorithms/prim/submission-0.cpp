class Solution {
public:
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {
        int res = 0;
        unordered_map<int, vector<pair<int, int>>> adj;
        for (int i=0; i<n; i++) {
            adj[i] = vector<pair<int, int>>();
        }
        for (vector<int> e : edges) {
            int n1 = e[0];
            int n2 = e[1];
            int w = e[2];
            adj[n1].push_back({n2, w});
            adj[n2].push_back({n1, w});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> mh;
        unordered_set<int> visit;
        for (pair<int, int> nei : adj[0]) {
            int node = nei.first;
            int wei = nei.second;
            mh.push({wei, 0, node});
        }
        visit.insert(0);
        while (visit.size() < n && !mh.empty()) { 
            vector<int> cur = mh.top();
            mh.pop();
            int wei = cur[0];
            int n1 = cur[1];
            int n2 = cur[2];
            res += wei;
            if (visit.count(n2) > 0) {
                continue;
            }
            visit.insert(n2);
            for (pair<int, int> neigh : adj[n2]) {
                if(visit.count(neigh.first) == 0) {
                    mh.push({neigh.second, n2, neigh.first});
                }
            }
        }
        return visit.size() == n ? res : -1;
    }
};

