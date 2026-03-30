class Solution {
public:
    bool search(vector<int>& nums, int target) {
       int l = 0, r = nums.size() - 1;
       while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) {
                l = mid + 1; 
            } else {
                r = mid;
            }
       }
       int pivot = l;
       l = 0;
       r = nums.size() - 1;
       if (target <= nums[r]) {
            l = pivot;
       } else {
            r = pivot - 1; 
       }
       while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (target > nums[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
       }
       return false;
    }
};