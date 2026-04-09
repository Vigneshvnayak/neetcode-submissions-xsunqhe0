class Solution {
public:
    int n;
    vector<vector<int>> res;
    void dfs(int start, vector<int>& nums, vector<int>& path, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        if (start == n || target < 0) return;
        for (int i = start; i < n; i++) {
            path.push_back(nums[i]);
            dfs(i, nums, path, target - nums[i]);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        n = nums.size();
        vector<int> path;
        dfs(0, nums, path, target);
        return res;
    }
};
