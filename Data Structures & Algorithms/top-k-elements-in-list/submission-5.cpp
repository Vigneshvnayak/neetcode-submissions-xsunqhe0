class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       int n = nums.size();
       vector<int> res;
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
       unordered_map<int, int> mp;
       for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
       }
       for (auto [key, value] : mp) {
            pq.push({value, key});
            if (pq.size() > k) {
                pq.pop();
            }
       }
       while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
       }
       return res;
    }
};
