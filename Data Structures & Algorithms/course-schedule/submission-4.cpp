class Solution {
unordered_map<int, vector<int>> mp;
unordered_set<int> visit;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       for (int i=0; i<numCourses; i++) {
        mp[i] = {};
       }
       for(auto& p : prerequisites) {
        mp[p[0]].push_back(p[1]);
       }
       for(int c=0; c<numCourses; c++) {
        if (!dfs(c)) {
            return false;
        }
        return true;
       }
    }
    bool dfs(int i) {
        if (visit.count(i)) {
            return false;
        }
        if(mp[i].empty()) {
            return true;
        }
        visit.insert(i);
        for (int p : mp[i]) {
            if (!dfs(p)) {
                return false;
            }
        }
        visit.erase(i);
        mp[i].clear();
        return true;     
    }
};
