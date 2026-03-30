class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxv, curv;
        maxv = curv = nums[0];
        for (int i=1; i<nums.size(); i++) {
            curv = max(curv + nums[i], nums[i]);
            maxv = max(curv, maxv);
        }
        return maxv;
    }
};
