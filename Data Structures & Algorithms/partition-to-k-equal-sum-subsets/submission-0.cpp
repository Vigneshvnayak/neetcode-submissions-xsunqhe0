class Solution {
public:
    int n;
    void dfs(int index, int sum, int& target, vector<int>& nums, int& k) {
        if (index == n) {
            if (sum == target) {
                k--;
            }
            return;
        }
        for (int i = index; i < n; i++) {
            if (sum + nums[i] <= target) {
                dfs(i + 1, sum + nums[i], target, nums, k);
            }
            dfs(i + 1, sum, target, nums, k);
        }
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % k != 0) return false;
        int target = total / k;
        dfs(0, 0, target, nums, k);
        if (k <= 0) {
            return true;
        }
        return false;
    }
};