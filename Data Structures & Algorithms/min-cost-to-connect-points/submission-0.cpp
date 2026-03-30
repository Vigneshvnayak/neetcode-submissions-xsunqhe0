class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
       unordered_map<int, vector<pair<int,int>>> adj;
       int n = points.size();
       for (int i=0; i<n; i++) {
        int x1 = points[i][0];
        int y1 = points[i][1];
        for (int j=i+1; j<n; j++) {
            int x2 = points[j][0];
            int y2 = points[j][1];
            int dist = abs(x1 - x2) + abs(y1 - y2);
            adj[i].push_back({j, dist});
            adj[j].push_back({i, dist});
        }
       }
       int res = 0;
       unordered_set<int> visit;
       priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
       for (pair<int, int> nei : adj[0]) {
        minheap.push({nei.second, 0, nei.first});
       }
       visit.insert(0);
       while (visit.size() < n && !minheap.empty()) {
        vector<int> cur = minheap.top();
        minheap.pop();
        int w1 = cur[0];
        int n1 = cur[1];
        int n2 = cur[2];
        if (visit.count(n2) > 0) {
            continue;
        }
        res += w1;
        visit.insert(n2);
        for (pair<int, int> nei : adj[n2]) {
            int neigh = nei.first;
            int nwei = nei.second;
            if (visit.count(neigh) == 0) {
                minheap.push({nwei, n2, neigh});
            }
          }
       }
       return res;
    }
};
