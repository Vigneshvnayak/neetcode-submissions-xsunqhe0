class Solution {
public:
    int house_robber(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        nums[n - 2] = max(nums[n - 2], nums[n - 1]);
        for (int i = n - 3; i >= 0; i--) {
            nums[i] = max(nums[i] + nums[i + 2], nums[i + 1]);
        }
        return nums[0];
    }
    int rob(vector<int>& nums) {
       if (nums.size() == 1) return nums[0];
       vector<int> n1(nums.begin(), nums.end() - 1);
       vector<int> n2(nums.begin() + 1, nums.end());
       return max(house_robber(n1), house_robber(n2));
    }
};
