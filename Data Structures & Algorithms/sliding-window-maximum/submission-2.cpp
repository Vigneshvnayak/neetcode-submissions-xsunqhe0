class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 1) return nums;
        priority_queue<pair<int, int>> pq;
        vector<int> res;
        int l = 0;
        for (int r = 0; r <= nums.size(); r++) {
            if (r - l + 1 > k) {
                int temp = pq.top().second;
                while (temp < l) {
                    pq.pop();
                }
                res.push_back(pq.top().first);
                l++;
            }
            pq.push({nums[r], r});
        }
        return res;
    }
};
