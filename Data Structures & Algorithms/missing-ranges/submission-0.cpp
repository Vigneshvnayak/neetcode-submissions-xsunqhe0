class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
       int n = nums.size();
       vector<vector<int>> res;
       if (n == 0) {
            res.push_back({lower, upper});
            return res;
       }
       if (lower < nums[0]) {
            res.push_back({lower, nums[0] - 1});
       }
       for (int i = 0; i < n -1; i++) {
            if (nums[i + 1] - nums[i] > 1) {
                res.push_back({nums[i] + 1, nums[i + 1] - 1});
            }
       }
       if (upper > nums[n - 1]) {
            res.push_back({nums[n - 1] + 1, upper});
       }
       return res;
    }
};
