class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
       #define MAXC 100
       vector <bool> res; 
       unordered_map<int, vector<int>> adj;
       vector<int> inorder(numCourses, 0);
       for (vector<int> p : prerequisites) {
            adj[p[0]].push_back(p[1]);
            inorder[p[1]]++;
       }
       queue<int> q;
       for (int i = 0; i < numCourses; i++) {
            if (inorder[i] == 0) {
                q.push(i);
            }
       }
       vector<int> order;
       while (!q.empty()) {
            int cur = q.front();
            q.pop();
            order.push_back(cur);
            for (int next : adj[cur]) {
                if (--inorder[next] == 0) {
                    q.push(next);
                }
            }
       }
       vector<bitset<MAXC>> prereq_map(numCourses);
       for (int cur : order) {
            for (int next : adj[cur]) {
                prereq_map[next] |=  prereq_map[cur];
                prereq_map[next].set(cur);
            }
       }
       for (vector<int> q : queries) {
            if (prereq_map[q[1]].test(q[0])) {
                res.push_back(true);
            } else {
                res.push_back(false);
            }
       }
       return res;
    }
};