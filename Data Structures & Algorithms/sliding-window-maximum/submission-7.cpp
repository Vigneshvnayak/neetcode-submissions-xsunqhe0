class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            while (!dq.empty() && nums[dq.back()] < nums[r]) {
                dq.pop_back();
            }
            dq.push_back(r);
            if (r - l + 1 > k) {
                if (dq.front() <= l) {
                    dq.pop_front();
                }
                l++;
            }
            if (r - l + 1 == k) {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};
