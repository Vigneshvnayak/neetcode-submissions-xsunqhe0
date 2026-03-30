class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        for (vector<int> t : triplets) {
            pq.push({t[0], t[1], t[2]});
        }
        int a = 0, b = 0, c = 0;
        while (!pq.empty()) {
            vector<int> t = pq.top();
            pq.pop();
            if (t[0] == target[0] && t[1] == target[1] &&
                t[2] == target[2]) {
                return true;
            }
            a = max(a, t[0]);
            b = max(b, t[1]);
            c = max(c, t[2]);
            if (a == target[0] && b == target[1] &&
                c == target[2]) {
                return true;
            }
        }
        return false;
    }
};
