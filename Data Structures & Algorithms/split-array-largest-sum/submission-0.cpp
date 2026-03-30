class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int r = accumulate(nums.begin(), nums.end(), 0);
        int l = *max_element(nums.begin(), nums.end());
        int res = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int sum = 0;
            int count = 1;
            for (int i = 0; i < nums.size(); i++) {
                if (sum + nums[i] > mid) {
                    count++;
                    sum = nums[i];
                } else {
                    sum += nums[i];
                }
            }
            if (count > k) {
                l = mid + 1;
            } else {
                res = mid;
                r = mid - 1;
            }

        }
        return res;
    }
};