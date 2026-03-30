class Solution {
public:
    bool dfs(int& i, int n, int minval, int maxval, vector<int>& preorder) {
        if (i == n) {
            return true;
        }
        int cur = preorder[i];
        if (cur <= minval || cur >= maxval) {
            return false;
        }
        i++;
        bool left = dfs(i, n, minval, cur, preorder);
        bool right = dfs(i, n, cur, maxval, preorder);
        return (left || right);
    }
    bool verifyPreorder(vector<int>& preorder) {
        int i = 0, n = preorder.size();
        return dfs(i, n, INT_MIN, INT_MAX, preorder);
    }
};
