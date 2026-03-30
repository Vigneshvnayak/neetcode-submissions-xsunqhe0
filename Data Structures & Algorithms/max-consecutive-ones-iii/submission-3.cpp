class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0, l = 0, res = 0;
        for (int r = 0; r < n; r++) {
            sum += nums[r];
            while ((r - l + 1) - sum > k) {
                sum -= nums[l];
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};