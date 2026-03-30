class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       vector<int> res;
       vector<vector<int>> preq(numCourses, vector<int>());
       vector<int> indegree(numCourses, 0);
       for (vector<int> p : prerequisites) {
            preq[p[1]].push_back(p[0]);
            indegree[p[0]]++;
       }
       queue<int> q;
       for (int i=0; i<numCourses; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
       }
       while (!q.empty()) {
        int cur = q.front();
        q.pop();
        res.push_back(cur);
        for (int nei : preq[cur]) {
            if (--indegree[nei] == 0) {
                q.push(nei);
            }
        }
       }
       return (res.size() == numCourses) ? res : vector<int>();
    }
};
