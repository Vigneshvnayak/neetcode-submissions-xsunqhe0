class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
       int l = 0, r = nums.size();
       while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }
            int size = (nums[mid] == nums[mid + 1]) ? mid - l : mid - 1 - l;
            if (size % 2 == 0) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
       }
       return -1;
    }
};