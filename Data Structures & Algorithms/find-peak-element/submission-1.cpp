class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size();
       while (l <= r) {
            int mid = l + (r - l) / 2;
            int prev = (mid - 1 == -1) ? INT_MIN : nums[mid - 1];
            int next = (mid + 1 == nums.size()) ? INT_MIN : nums[mid + 1];
            if (prev < nums[mid] && next < nums[mid]) {
                return mid;
            } else if (prev > next){
                r = mid - 1;
            } else {
                l = mid + 1;
            }
       }
       return 0;
    }
};