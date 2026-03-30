class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        if (sticks.size() <= 1) {
            return 0;
        }
        int cost = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int s : sticks) {
            pq.push(s);
        }
        while (pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            int temp = x + y;
            cost += temp;
            pq.push(temp);
        }
        return cost;
    }
};
