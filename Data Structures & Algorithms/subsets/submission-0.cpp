class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> res;
       vector<int>sb;
       dfs(nums, 0, sb, res);
       return res; 
    }
    void dfs(vector<int> &nums, int i, vector<int> &sb, vector<vector<int>> &res) {
        if (i >= nums.size()) {
            res.push_back(sb);
            return;
        }
        sb.push_back(nums[i]);
        dfs(nums, i+1, sb, res);
        sb.pop_back();
        dfs(nums, i+1, sb, res);
    }
};
