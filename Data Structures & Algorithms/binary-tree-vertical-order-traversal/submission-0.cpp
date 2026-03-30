/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void dfs(TreeNode* root, map<int, vector<int>>& mp, int key) {
        if (!root) {
            return;
        }
        mp[key].push_back(root->val);
        dfs(root->left, mp, key - 1);
        dfs(root->right, mp, key + 1);
        return;
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        map <int, vector<int>> mp;
        dfs(root, mp, 0);
        for (auto [key, value] : mp) {
            res.push_back(value);
        }
        return res;
    }
};