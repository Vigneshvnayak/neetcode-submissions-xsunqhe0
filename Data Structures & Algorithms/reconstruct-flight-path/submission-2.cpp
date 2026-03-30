class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> mp; 
        queue<string> q;
        for (vector<string> t : tickets) {
            mp[t[0]].push(t[1]);
        }
        q.push("JFK");
        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            res.push_back(cur);
            if (!mp[cur].empty()) {
                string nei = mp[cur].top();
                mp[cur].pop();
                q.push(nei);
            }
        }
        return res;
    }    

};
