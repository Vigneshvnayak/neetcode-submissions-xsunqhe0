class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
       long long res = 0; 
       priority_queue<int> pq;
       for (int g : gifts) {
            pq.push(g);
       }
       while(k > 0) {
            int g = pq.top();
            pq.pop();
            int f = floor(sqrt(g));
            pq.push(f);
            k--;
       }
       while (!pq.empty()) {
            res += pq.top();
            pq.pop();
       }
       return res;
    }
};