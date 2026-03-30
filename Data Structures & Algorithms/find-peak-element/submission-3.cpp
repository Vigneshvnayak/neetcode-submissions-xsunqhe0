class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
       while (l <= r) {
            int mid = l + (r - l) / 2;
            long long prev = (mid - 1 == -1) ? LLONG_MIN : nums[mid - 1];
            long long next = (mid + 1 == nums.size()) ? LLONG_MIN : nums[mid + 1];
            if (nums[mid] > prev && nums[mid] > next) {
                return mid;
            } else if (prev > nums[mid]){
                r = mid - 1;
            } else {
                l = mid + 1;
            }
       }
       return 0;
    }
};