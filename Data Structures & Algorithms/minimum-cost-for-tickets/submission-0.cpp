class Solution {
public:
    int dfs(int i, vector<int>& days, vector<int>& costs, unordered_map<int, int> &mp) {
        if (i == days.size()) {
            return 0;
        }
        if (mp.count(i)) {
            return mp[i];
        }
        mp[i] = INT_MAX;
        int idx = 0;
        for (int d : {1, 7, 30}) {
            int j = i;
            while (j < days.size() && days[j] < days[i] + d) {
                j++;
            }
            mp[i] = min(mp[i], costs[idx] + dfs(j, days, costs, mp));
            idx++;
        }
        return mp[i];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
       unordered_map<int, int> mp; 
       return dfs(0, days, costs, mp);
    }
};