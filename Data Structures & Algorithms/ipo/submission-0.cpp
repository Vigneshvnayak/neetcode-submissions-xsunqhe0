class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq;
        vector<vector<int>> sorted;
        for (int i = 0; i < capital.size(); i++) {
            sorted.push_back({capital[i], profits[i]});
        }
        sort(sorted.begin(), sorted.end());
        int i = 0;
        int total = w;
        for (i; i < sorted.size(); i++) {
            if (sorted[i][0] <= total) {
                pq.push(sorted[i][1]);
            } else {
                break;
            }
        }
        while (!pq.empty() && k) {
            total += pq.top();
            pq.pop();
            k--;
            for (i; i < sorted.size(); i++) {
                if (sorted[i][0] <= total) {
                    pq.push(sorted[i][1]);
                } else {
                    break;
                }
            }
        }
        return total;
    }
};