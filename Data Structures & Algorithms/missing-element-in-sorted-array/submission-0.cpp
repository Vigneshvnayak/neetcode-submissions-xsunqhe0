class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int l = nums.front();
        int r = nums.back();
        while (l < r) {
            int mid = l + (r - l) / 2;
            int count = upper_bound(nums.begin(), nums.end(), mid) - nums.begin();
            int missing = mid - nums[0] + 1 - count;
            if (missing >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
