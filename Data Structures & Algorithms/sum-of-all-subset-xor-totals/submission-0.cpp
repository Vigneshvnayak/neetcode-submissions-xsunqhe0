class Solution {
public:
    int sum = 0;
    int n; 
    void dfs(int index, int val, vector<int>& nums) {
        if (index == n) {
            sum += val;
            return;
        }
        if (index > n) {
            return;
        }
        dfs(index + 1, val, nums);
        dfs(index + 1, val ^ nums[index], nums);
        return;
    }
    int subsetXORSum(vector<int>& nums) {
        n = nums.size();
        dfs(0, 0, nums);
        return sum;
    }
};
