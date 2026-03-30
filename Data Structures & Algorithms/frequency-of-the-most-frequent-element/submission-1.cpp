class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
       sort(nums.begin(), nums.end());
       int n = nums.size();
       int res = 0, total = 0, l = 0;
       for (int r = 0; r < n; r++) {
            total += nums[r];
            while ((r - l + 1) * nums[r] - total > k) {
                total -= nums[l];
                l++;
            }
            res = max(res, r - l + 1);
       }
       return res;
    }
};