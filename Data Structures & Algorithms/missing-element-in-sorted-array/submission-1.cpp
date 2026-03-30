class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = right - (right - left) / 2;
            int count = nums[mid] - nums[0] - mid;
            if (count < k) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return nums[0] + left + k;
    }
};
