class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
       vector <bool> res; 
       unordered_map<int, vector<int>> adj;
       vector<int> inorder(numCourses, 0);
       for (vector<int> p : prerequisites) {
            adj[p[0]].push_back(p[1]);
            inorder[p[1]]++;
       }
       queue<int> q;
       unordered_map<int, unordered_set<int>> mp;
       for (int i = 0; i < numCourses; i++) {
            if (inorder[i] == 0) {
                q.push(i);
                mp[i];
            }
       }
       while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int next : adj[cur]) {
                mp[next].insert(mp[cur].begin(), mp[cur].end());
                mp[next].insert(cur);
                if (--inorder[next] == 0) {
                    q.push(next);
                }
            }
       }
       for (vector<int> q : queries) {
            if (mp[q[1]].count(q[0])) {
                res.push_back(true);
            } else {
                res.push_back(false);
            }
       }
       return res;
    }
};