class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq) {
       vector<int> res; 
       vector<int> indegree(numCourses, 0);
       vector<vector<int>> nei(numCourses, vector<int>());
       queue<int> q;
       for (int i = 0; i < prereq.size(); i++) {
            indegree[prereq[i][0]]++;
            nei[prereq[i][1]].push_back(prereq[i][0]);
       }
       for (int i = 0; i < numCourses; i++) {
            if (!indegree[i]) {
                q.push(i);
            }
       }
       while (!q.empty()) {
            int u = q.front();
            q.pop();
            res.push_back(u);
            for (int v : nei[u]) {
                if (--indegree[v] == 0) {
                    q.push(v);
                }
            }
       }
       if (res.size() != numCourses) {
            return {};
       }
       return res;
    }
};
