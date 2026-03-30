class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> inorder(numCourses, 0);
        for (vector<int> p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            inorder[p[0]]++;
        }
        queue<int> q;
        unordered_set<int> s;
        for (int i = 0; i < numCourses; i++) {
            if (inorder[i] == 0) {
                q.push(i);
                s.insert(i);
            }
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            s.insert(cur);
            for (int next : adj[cur]) {
                if (--inorder[next] == 0) {
                    q.push(next);
                }
            }
        }
        return (s.size() == numCourses) ? true : false;
    }
};
