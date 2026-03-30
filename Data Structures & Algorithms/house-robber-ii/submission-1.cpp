class Solution {
public:
    int helper(vector<int>& nums, int start, int end) {
        int prev = 0, cur = 0;
        for (int i=start; i<=end; i++) {
            int temp = max(cur, nums[i] + prev);
            prev = cur;
            cur = temp;
        }
        return cur;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return max(nums[0], max(helper(nums, 0, n-2), helper(nums, 1, n-1)));
    }
};
