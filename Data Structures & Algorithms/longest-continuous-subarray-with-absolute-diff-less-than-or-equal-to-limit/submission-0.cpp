class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
       int n = nums.size();
       int res = 0; 
       int l = 0, r = 0;
       int minval = INT_MAX, maxval = INT_MIN;
       while (r < n) {
            minval = min(minval, nums[r]);
            maxval = max(maxval, nums[r]);
            if (abs(maxval - minval) > limit) {
                l++;
                minval = *min_element(nums.begin() + l, nums.begin() + r);
                maxval = *max_element(nums.begin() + l, nums.begin() + r);
            } else {
                if (res < r - l + 1) {
                    res = r - l + 1;
                }
                r++;
            }
       }
       return res;
    }
};