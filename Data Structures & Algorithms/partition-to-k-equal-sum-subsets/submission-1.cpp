class Solution {
public:
    int n;
    bool dfs(int index, vector<int>& sums, int& target, vector<int>& nums) {
        if (index == n) {
            for (int s : sums) {
                if (s != target) {
                    return false;
                }
            }
            return true;
        }
        for (int i = 0; i < sums.size(); i++) {
            if (sums[i] + nums[index] <= target) {
                sums[i] += nums[index];
                if (dfs(index + 1, sums, target, nums)) {
                    return true;
                }
                sums[i] -= nums[index];
                if (sums[i] == 0) break;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n = nums.size();
        sort(nums.rbegin(), nums.rend());
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % k != 0) return false;
        int target = total / k;
        vector<int> sums(k, 0);
        return dfs(0, sums, target, nums);
    }
};