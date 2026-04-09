class Solution {
public:
    vector<vector<int>> res;
    void dfs(int index, vector<int>& temp, int n, int k) {
        if (index > n) {
            if (temp.size() == k) {
                res.push_back(temp);
            }
            return;
        }
        temp.push_back(index);
        dfs(index + 1, temp, n, k);
        temp.pop_back();
        dfs(index + 1, temp, n, k);
        return;
    }
    vector<vector<int>> combine(int n, int k) {
       vector<int> temp;
       dfs(1, temp, n, k);
       return res;
    }
};