class Solution {
    unordered_map<string, int> memo;
public:
    int lengthOfLIS(vector<int>& nums) {
	return dfs(0, nums, -1001);
    }

    int dfs(int index, vector<int>& nums, int prev) {
        if (index >= nums.size()) {
            return 0;
        }
        string key = to_string(index) + "_" + to_string(prev);
        if (memo.count(key) > 0) {
            return memo[key];
        }
        memo[key] = dfs(index+1, nums, prev);
        if (prev < nums[index]) {
            memo[key] = max(memo[key], 1 + dfs(index+1, nums, nums[index]));
        }
        return memo[key];
    }

};
