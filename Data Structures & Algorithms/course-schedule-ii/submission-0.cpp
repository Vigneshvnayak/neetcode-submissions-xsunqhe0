class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       unordered_map<int, vector<int>> adj;
       unordered_map<int, int> indegree;
       for (vector<int> &p : prerequisites) {
        indegree[p[0]]++;
        adj[p[1]].push_back(p[0]);
       }
       queue<int> q;
       for (int i=0; i<numCourses; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
       }
       vector<int> output;
       int count = 0;
       while (!q.empty()) {
        int c = q.front();
        q.pop();
        output.push_back(c);
        count++; 
        for (int &a : adj[c]) {
            indegree[a]--;
            if (indegree[a] == 0) {
                q.push(a);
            }
        }
       }
       return count != numCourses ? vector<int>() : output;
    }
};
