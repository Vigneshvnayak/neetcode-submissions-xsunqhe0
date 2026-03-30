class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        int n = queries.size();
        vector<int> sorted_queries = queries;
        sort(sorted_queries.begin(), sorted_queries.end());
        auto cmp = [](const vector<int>& a, const vector<int>& b){
            return a[0] > b[0] || (a[0] == b[0] && a[1] > b[1]);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        unordered_map<int, int> mp;
        int i = 0;
        for (int q : sorted_queries) {
           while (i < intervals.size() && intervals[i][0] <= q) {
                pq.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                i++;
           }
           while (!pq.empty() && pq.top()[1] < q) {
                pq.pop();
           }
           mp[q] = (!pq.empty()) ? pq.top()[0] : -1;
        }
        vector<int> res(n, -1);
        for (int i = 0; i < n; i++) {
            res[i] = mp[queries[i]];
        }
        return res;
    }
};
