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
	return dfs(0, nums, 0, target);
}

bool dfs(int index, vector<int>& nums, int sum, int target) {
	if (index == nums.size()) {
		return sum == target;
	}
    if (sum > target) {
		return false;
	}
	if (memo[index][sum] != -1) {
		return memo[index][sum];
	}
	memo[index][sum] = dfs(index+1, nums, sum + nums[index], target) || dfs(index+1, nums, sum, target);
	return memo[index][sum];
}

};
