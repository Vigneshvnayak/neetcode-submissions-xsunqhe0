class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, prod = 1, res = 0;
        for (int r = 0; r < n; r++) {
            prod *= nums[r];
            while (l <= r && prod >= k) {
                if (prod != 1) {
                    prod /= nums[l];
                }
                l++;
            }
            res += (r - l + 1);
        }
        return res;
    }
};