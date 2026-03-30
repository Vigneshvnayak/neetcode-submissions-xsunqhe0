class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
       unordered_map<int, vector<pair<int, int>>> adj;
       int n = points.size();
       for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < n; j++) {
               int x2 = points[j][0];
               int y2 = points[j][1];
               int dist = abs(x1 - x2) + abs(y1 - y2);
               adj[i].push_back({j, dist});
            }
       }
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
       for (pair<int, int> nei : adj[0]) {
            pq.push({nei.second, nei.first});
       }
       unordered_set<int> visit;
       visit.insert(0);
       int res = 0;
       while (visit.size() < n) {
            pair<int, int> cur = pq.top();
            pq.pop();
            int dist = cur.first;
            int next = cur.second;
            if (visit.count(next)) {
                continue;
            }
            res += dist;
            visit.insert(next);
            for (pair<int, int> nei : adj[next]) {
                if (!visit.count(nei.first)) {
                    pq.push({nei.second, nei.first});
                }
            }
       }
       return res;
    }
};
