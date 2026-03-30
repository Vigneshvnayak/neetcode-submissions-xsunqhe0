class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
       int n = nums.size();
       int l = 0, r = n - 1;
       while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((mid - 1 < 0 || nums[mid - 1] != nums[mid]) &&
            (mid + 1 == n || nums[mid + 1] != nums[mid])) {
                return nums[mid];
            }
            int size = (nums[mid] == nums[mid + 1]) ? mid : mid - 1;
            if (!(size % 2)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
       }
       return -1;
    }
};