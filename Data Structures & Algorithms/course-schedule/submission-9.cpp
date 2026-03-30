class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector<int> indegree(numCourses, 0);
       vector<vector<int>> adj;
       for (int i=0; i<numCourses; i++) {
        adj.push_back(vector<int>());
       }
       for(vector<int> p : prerequisites) {
        indegree[p[0]]++;
        adj[p[1]].push_back(p[0]);
       }
       queue<int> q;
       for (int i=0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
       }
       int num = 0;
       while (!q.empty()) {
        int c = q.front();
        q.pop();
        num++;
        for (int a : adj[c]) {
            indegree[a]--;
            if(indegree[a] == 0) {
                q.push(a);
            }
         }
       }
       return (num == numCourses) ? true : false;
    }
};
