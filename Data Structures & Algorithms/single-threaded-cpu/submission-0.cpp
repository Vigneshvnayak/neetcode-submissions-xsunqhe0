class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int i = 0;
        int n = tasks.size();
        for (int j = 0; j < n; j++) {
            tasks[j].push_back(j);
        }
        sort(tasks.begin(), tasks.end());
        long long curtime;
        vector<int> res;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        while (!pq.empty() || i < n) {
            while (i < n && (curtime >= tasks[i][0])) {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }
            if (pq.empty()) {
                curtime = tasks[i][0];
            } else {
                vector<int> x = pq.top();
                pq.pop();
                curtime += x[0];
                res.push_back(x[1]);
            }
        }
        return res;
    }
};