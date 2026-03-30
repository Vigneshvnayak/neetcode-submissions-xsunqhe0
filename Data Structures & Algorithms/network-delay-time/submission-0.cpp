class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       unordered_map<int, vector<pair<int, int>>> adj;
       for (int i=1; i<n+1; i++) {
        adj[i] = vector<pair<int, int>>();
       }
       for (vector<int> t : times) {
        adj[t[0]].push_back({t[1], t[2]});
       }
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mh;
       set<int> v;
       mh.push({0, k});
       int t = 0;
       while (!mh.empty()) {
        pair<int, int> temp = mh.top();
        mh.pop();
        int n1 = temp.second;
        int w1 = temp.first;
        if (v.count(n1)) {
            continue;
        } 
        v.insert(n1);
        t = w1;
        if (adj.count(n1)) {
            for (pair<int, int> nod : adj[n1]) {
                int n2 = nod.first;
                int w2 = nod.second;
                if (!v.count(n2)) {
                    mh.push({w2 + w1, n2});
                }
            }
         }
       }
        return v.size() == n ? t : -1;
    }
};
