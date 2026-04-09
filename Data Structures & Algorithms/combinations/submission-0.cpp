class Solution {
public:
    vector<vector<int>> res;
    void dfs(int index, vector<int>& temp, int n, int k) {
        if (temp.size() == k) {
            res.push_back(temp);
            return;
        }
        for (int i = index; i <= n; i++) {
            temp.push_back(i);
            dfs(i + 1, temp, n, k);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
       vector<int> temp; 
       dfs(1, temp, n, k);
       return res;
    }
};