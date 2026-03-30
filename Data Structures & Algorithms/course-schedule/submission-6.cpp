class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector<int> indegree(numCourses, 0);
       vector<vector<int>> adj(numCourses);
       queue<int> q;
       for (auto& p : prerequisites) {
        indegree[p[1]]++;
        adj[p[0]].push_back(p[1]);
       }
       for(int i=0; i<numCourses; i++) {
        if(indegree[i] == 0){
            q.push(i);
        }
       }
       int final = 0;
       while (!q.empty()) {
        int t = q.front();
        q.pop();
        final++;
        for(int n : adj[t]) {
            if (--indegree[n] == 0) {
                q.push(n);
            }
        }
       }
       return final == numCourses;

    }
};
