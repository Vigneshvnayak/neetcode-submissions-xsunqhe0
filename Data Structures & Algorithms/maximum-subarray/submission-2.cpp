class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxv = 0;
        int sum = 0;
        for (int i=0; i<nums.size(); i++) {
            sum = max(sum + nums[i], nums[i]);
            maxv = max(maxv, sum);
        }
        return maxv;

    }
};
