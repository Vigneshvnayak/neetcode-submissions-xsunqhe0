class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       vector<int> res;
       unordered_map<int, vector<int>> adj;
       vector<int> inorder(numCourses, 0);
       for (vector<int> p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            inorder[p[0]]++;
       }
       queue<int> q;
       for (int i = 0; i < numCourses; i++) {
            if (!inorder[i]) {
                q.push(i);
            }
       }
       while (!q.empty()) {
            int cur = q.front();
            q.pop();
            res.push_back(cur);
            for (int next : adj[cur]) {
                if (--inorder[next] == 0) {
                    q.push(next);
                }
            }
       }
       if (res.size() == numCourses) {
            return res;
       }
       return {};
    }
};
