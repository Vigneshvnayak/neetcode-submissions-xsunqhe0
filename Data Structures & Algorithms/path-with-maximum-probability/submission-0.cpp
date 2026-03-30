class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
       unordered_map<int, vector<pair<int, double>>> adj; 
       for (int i = 0; i < n; i++) {
            adj[i] = vector<pair<int, double>>();
       }
       for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
       }
       priority_queue<pair<double, int>> pq;
       unordered_set<int> s;
       pq.push({1.0, start_node});
       while (!pq.empty()) {
            pair<double, int> cur = pq.top();
            pq.pop();
            double prob = cur.first;
            int curnode = cur.second;
            if (curnode == end_node) {
                return prob;
            }
            if (s.count(curnode)) {
                continue;
            }
            s.insert(curnode);
            for (pair<int, double> nei : adj[curnode]) {
                int newcurnode = nei.first;
                double newprob = nei.second;
                if (!s.count(newcurnode)) {
                    pq.push({prob * newprob, newcurnode});
                }
            }
       }
       return 0.0; 
    }
};