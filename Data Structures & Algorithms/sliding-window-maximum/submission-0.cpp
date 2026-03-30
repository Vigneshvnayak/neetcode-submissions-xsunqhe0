class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       int mv = INT_MIN;
       vector<int> res;
       int l = 0;
       int r = 1;
       while (r <= nums.size()) {
        if (r >= l + k) {
            res.push_back(mv);
            l++;
        } else {
            mv = max(mv, nums[r]);
            r++;
        }
       }
       return res;
    }
};
