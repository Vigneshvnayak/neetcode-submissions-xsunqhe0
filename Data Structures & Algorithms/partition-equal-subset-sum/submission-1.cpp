class Solution {
public:
    vector<vector<int>> memo;
bool canPartition(vector<int>& nums) {
	int sum = 0;
	for (int i=0; i<nums.size(); i++) {
		sum += nums[i];
	}
    if (sum % 2 != 0) {
        return false;
    }
    int target = sum / 2;
	memo.assign(nums.size(), vector<int>(target + 1, -1));
	return dfs(0, nums, target);
}

bool dfs(int index, vector<int>& nums, int target) {
	if (index == nums.size()) {
		return target == 0;
	}
    if (target < 0) {
		return false;
	}
	if (memo[index][target] != -1) {
		return memo[index][target];
	}
	memo[index][target] = dfs(index+1, nums,target - nums[index]) || dfs(index+1, nums, target);
	return memo[index][target];
}

};
