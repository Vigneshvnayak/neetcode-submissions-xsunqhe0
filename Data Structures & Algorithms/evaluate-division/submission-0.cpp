class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        vector<double> final_res; 
        unordered_map<string, vector<pair<string, double>>> adj;
        for (int i = 0; i < n; i++) {
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }
        for (vector<string> query : queries) {
            string start = query[0], target = query[1];
            if (adj.find(start) == adj.end() || adj.find(target) == adj.end()) {
                final_res.push_back(-1.0);
                continue;
            }
            queue<pair<string, double>> q;
            unordered_set<string> visit;
            q.push({start, 1.0});
            visit.insert(start);
            bool found = false;
            while (!q.empty()) {
                pair<string, double> cur = q.front();
                q.pop();
                if (cur.first == target) {
                    final_res.push_back(cur.second);
                    found = true;
                    break;
                }
                for (pair<string, double> nei : adj[cur.first]) {
                    if (!visit.count(nei.first)) {
                        visit.insert(nei.first);
                        q.push({nei.first, cur.second * nei.second});
                    }
                }
            }
            if (!found) {
                final_res.push_back(-1.0);
            }
        }
        return final_res;
    }
};