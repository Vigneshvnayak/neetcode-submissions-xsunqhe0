class Solution {
public:
    void dfs(const string str, unordered_map<string, deque<string>> &mp,
            vector<string> &res) {
            while (!mp[str].empty()) {
                string cur = mp[str].back();
                mp[str].pop_back();
                dfs(cur, mp, res);
            }
            res.push_back(str);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        unordered_map<string, deque<string>> mp;
        for (vector<string> t : tickets) {
            mp[t[0]].push_back(t[1]);
        }
        for(auto [start, end] : mp) {
            sort(end.rbegin(), end.rend());
        }
        vector<string> res;
        dfs("JFK", mp, res);
        reverse(res.begin(), res.end());
        return res;
    }
};
