class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
       priority_queue<int> pq;
       for (int s : stones) {
        pq.push(s);
       } 
       while (pq.size() > 1) {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        if (x > y) {
            pq.push(x-y);
        } else {
            pq.push(0);
            }
        }
       return pq.top();
    }
};
