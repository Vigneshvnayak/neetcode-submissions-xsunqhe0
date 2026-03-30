class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0, maxsum = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            cur = max(cur + nums[i], nums[i]);
            maxsum = max(maxsum, cur);
        }
        return maxsum;
    }
};
