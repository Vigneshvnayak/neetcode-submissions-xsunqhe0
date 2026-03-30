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
    bool dfs(long long min, long long max, TreeNode* root) {
        if (!root) {
            return true;
        }
        if (!(root->val > min && root->val < max)) {
            return false;
        }
        return dfs(min, root->val, root->left) && dfs(root->val, max, root->right);
    }

    bool isValidBST(TreeNode* root) {
        return dfs(INT_MIN, INT_MAX, root);
    }
};
