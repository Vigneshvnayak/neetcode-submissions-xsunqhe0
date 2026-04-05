class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax = 1, curMin = 1;
        int res = INT_MIN;
        for (int n : nums) {
            int temp = curMax;
            curMax = max({curMax * n, curMin * n, n});
            curMin = min({temp * n, curMin * n, n});
            res = max(res, curMax);
        }
        return res;
    }
};
