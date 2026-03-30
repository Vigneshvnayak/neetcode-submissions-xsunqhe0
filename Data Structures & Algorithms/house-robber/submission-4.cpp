class Solution {
public:
    int rob(vector<int>& nums) {
        int s = nums.size();
        if (s == 1) {
            return nums[0];
        }
        if (s == 2) {
            return max(nums[0], nums[1]);
        }
        if (s == 3) {
            return max(nums[0] + nums[2], nums[1]);
        }
        nums[s-2] = max(nums[s-2], nums[s-1]);
        for (int i = s-3; i>=0; i--) {
            nums[i] = nums[i] + nums[i+2];
            nums[i] = max(nums[i+1], nums[i]);
        }
        return nums[0];
    }
};
