class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int n : nums) {
            mp[n]++;
        }
        for (int i = 0; i < n; i++) {
            mp[nums[i]]--;
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }
            for (int j = i + 1; j < n; j++) {
                mp[nums[j]]--;
                if (j > i + 1 && nums[j - 1] == nums[j]) {
                    continue;
                }
                int target = -(nums[i] + nums[j]);
                if (mp[target] > 0) {
                    res.push_back({nums[i], nums[j], target});
                }
            }
            for (int j = i + 1; j < n; j++) {
                mp[nums[j]]++;
            }
        }
        return res;
    }
};
