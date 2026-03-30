class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, vector<pair<int, int>>> mp;
        int n = points.size();
        for (int i=0; i<n; i++) {
            mp[i] = vector<pair<int, int>>();
        }
        for (int i=0; i<n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j=i+1; j<n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int d = abs(x1 - x2) + abs(y1 - y2);
                mp[i].push_back({j, d});
                mp[j].push_back({i, d});
            }
        }
        for (pair<int, int> nei : mp[0]) {
            pq.push({nei.second, nei.first});
        }
        unordered_set<int> visit;
        visit.insert(0);
        int res=0;
        while (visit.size() < n && !pq.empty()) {
            pair<int, int> c = pq.top();
            pq.pop();
            int d = c.first;
            int nei = c.second;
            if (visit.count(nei) > 0) {
                continue;
            }
            visit.insert(nei);
            res += d;
            for (pair<int, int> a : mp[nei]) {
                pq.push({a.second, a.first});
            }
        }
        return res;
    }
};
