class Solution {
public:
    vector<vector<int>> res;
    int n;
    void dfs(int index, vector<int>& temp, vector<int>& nums) {
        if (index == n) {
            res.push_back(temp);
            return;
        }
        dfs(index + 1, temp, nums);
        temp.push_back(nums[index]);
        dfs(index + 1, temp, nums);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> temp;
        dfs(0, temp, nums);
        return res;
    }
};
