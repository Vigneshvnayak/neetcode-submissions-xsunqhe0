class Solution {
public:
    vector<vector<int>> res;
    int n;
    unordered_set<int> s;
    void dfs(vector<int>& temp, vector<int>& nums) {
        if (temp.size() == nums.size()) {
            res.push_back(temp);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!s.count(i)) {
                s.insert(i);
                temp.push_back(nums[i]);
                dfs(temp, nums);
                temp.pop_back();
                s.erase(i);
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<int> temp;
        dfs(temp, nums);
        return res;
    }
};