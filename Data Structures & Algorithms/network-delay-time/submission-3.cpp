class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> mp;
        for (int i=1; i<n+1; i++) {
            mp[i] = vector<pair<int,int>>();
        }
        for (vector<int> t : times) {
            mp[t[0]].push_back({t[1], t[2]});
        }
        unordered_set<int> visit;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});
        int res=0;
        while (!pq.empty()) {
            auto [time, cur] = pq.top();	
            pq.pop();
            if (visit.count(cur) > 0) {
                continue;
            }
            res = time;
            visit.insert(cur);
            for (auto [nei, newtime] : mp[cur]) {
                if (visit.count(nei) == 0) {
                    pq.push({time + newtime, nei});
                }
            }
        }
        return visit.size() == n ? res : -1;
    
    }
};
