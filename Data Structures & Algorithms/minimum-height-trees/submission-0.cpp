class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<int> res;
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for (vector<int> e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 1) {
                q.push(i);
            }
        }
        int remain = n;
        while (remain > 2) {
           int leaf = q.size();
           remain -= leaf;
           for (int i = 0; i < leaf; i++) {
                int cur = q.front();
                q.pop();
                for (int nei : adj[cur]) {
                    indegree[nei]--;
                    if (indegree[nei] == 1) {
                        q.push(nei);
                    }
                }
           }
        }
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};