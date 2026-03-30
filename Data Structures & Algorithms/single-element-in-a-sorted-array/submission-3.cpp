class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
       int l = 0, r = nums.size() - 1;
       while (l <= r) {
            int mid = l + (r - l) / 2;
            int next = (mid + 1 == nums.size()) ? INT_MAX : nums[mid + 1];
            int prev = (mid - 1 < 0) ? INT_MIN : nums[mid - 1];
            if (nums[mid] != prev && nums[mid] != next) {
                return nums[mid];
            }
            int size = (nums[mid] == next) ? mid - l : mid - 1 - l;
            if (size % 2 == 0) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
       }
       return -1;
    }
};