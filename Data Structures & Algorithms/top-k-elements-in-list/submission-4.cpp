class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int, int> mp; 
       priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
       vector<int> res;
       for (int n : nums) {
            mp[n]++;
       }
       for (auto kv : mp) {
            pq.push({kv.second, kv.first});
            if (pq.size() > k) {
                pq.pop();
            }
       }
       while (!pq.empty()) {
            res.push_back(pq.top()[1]);
            pq.pop();
       }
        return res;
    }
};
