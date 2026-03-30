class Solution {
public:
    set<vector<int>> s;
    int n;
    void dfs(vector<int>& temp, vector<int>& nums) {
        if (temp.size() == nums.size()) {
            s.insert(temp);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != INT_MIN) {
                int t = nums[i];
                temp.push_back(t);
                nums[i] = INT_MIN;
                dfs(temp, nums);
                nums[i] = t;
                temp.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       n = nums.size();
       vector<int> temp;
       dfs(temp, nums);
       vector<vector<int>> res(s.begin(), s.end());
       return res;
    }
};