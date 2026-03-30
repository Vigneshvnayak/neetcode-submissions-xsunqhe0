class Solution {
public:
    vector<vector<int>> res;
    int n;
    void dfs(unordered_set<int>& s, vector<int>& nums) {
        if (s.size() == nums.size()) {
            vector<int> temp(s.begin(), s.end());
            res.push_back(temp);
            return;
        }
        for (int c : nums) {
            if (!s.count(c)) {
                s.insert(c);
                dfs(s, nums);
                s.erase(c);
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        dfs(s, nums);
        return res;
    }
};
