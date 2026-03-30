class Solution {
unordered_map<int, vector<int>> adj;
unordered_set<int> visit;
unordered_set<int> cycle;
vector<int> output;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       for (vector<int> &p : prerequisites)  {
          adj[p[0]].push_back(p[1]);
       }
       for (int i=0; i < numCourses; i++) {
        if (!dfs(adj, visit, cycle, output, i)) {
            return {};
        }
       }
       return output;
    }
    bool dfs(unordered_map<int, vector<int>>& adj,
            unordered_set<int>& visit, unordered_set<int>& cycle,
            vector<int>& output, int c) {
                if (cycle.count(c) > 0) {
                    return false;
                }
                if(visit.count(c) > 0) {
                    return true;
                }
                cycle.insert(c);
                for (int &a : adj[c]) {
                    if(!dfs(adj, visit, cycle, output, a)) {
                        return false;
                    }
                }
                visit.insert(c);
                cycle.erase(c);
                output.push_back(c);
                return true;
            }
};
