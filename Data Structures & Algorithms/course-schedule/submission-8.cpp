class Solution {
unordered_map<int, vector<int>> adj;
unordered_set<int> visit;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       for (int i=0; i < numCourses; i++) {
        adj[i] = vector<int>();
       }
       for (vector<int> &p : prerequisites) {
        adj[p[0]].push_back(p[1]);
       }
       for (int i=0; i < numCourses; i++) {
        if (!dfs(i)) {
            return false;
        }
       }
       return true;
    }
    bool dfs(int c) {
        if (visit.count(c) > 0) {
            return false;
        }
        if (adj[c].empty()) {
            return true;
        }
        visit.insert(c);
        for (int &a : adj[c]) {
            if (!dfs(a)) {
                return false;
            }
        }
        visit.erase(c);
        adj[c].clear();
        return true;
    }
};
