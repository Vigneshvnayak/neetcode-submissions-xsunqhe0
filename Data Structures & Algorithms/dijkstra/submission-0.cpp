class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
       unordered_map<int, vector<pair<int, int>>> adj;
       for (int i=0; i<n; i++) {
        adj[i] = vector<pair<int,int>>();
       }
       for(vector<int> e : edges) {
        adj[e[0]].push_back({e[1], e[2]}); 
       }
       unordered_map<int, int> shortest;
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
       minheap.push({0, src});
       while (!minheap.empty()) {
        pair<int, int> temp = minheap.top();
        int w = temp.first;
        int n = temp.second;
        minheap.pop();
        if (shortest.count(n) > 0) {
            continue;
        }
        shortest[n] = w;
        for (pair<int, int>& e : adj[n]) {
            int n2 = e.first;
            int w2 = e.second;
            if (shortest.count(n2) == 0) {
                minheap.push({w2 + w, n2});
            }
         }
       }
       for (int i = 0; i < n; i++) {
            if (shortest.find(i) == shortest.end()) {
                shortest[i] = -1;
            }
        }

       return shortest;

    }
};
