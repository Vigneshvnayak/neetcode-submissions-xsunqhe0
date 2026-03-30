class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        deque<int> maxq, minq;
        int l = 0, res = 0;
        for (int r = 0; r < n; r++) {
            while (!minq.empty() && minq.back() > nums[r]) {
                minq.pop_back();
            }
            while (!maxq.empty() && maxq.back() < nums[r]) {
                maxq.pop_back();
            }
            minq.push_back(nums[r]);
            maxq.push_back(nums[r]);
            if (maxq.front() - minq.front() > limit) {
                if (nums[l] == maxq.front()) {
                    maxq.pop_front();
                }
                if (nums[l] == minq.front()) {
                    minq.pop_front();
                }
                l++;
            }
            if (res < r - l + 1) {
                res = r - l + 1;
            }
        }
        return res;
    }
};