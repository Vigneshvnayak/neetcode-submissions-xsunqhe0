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
    int mv = INT_MIN;
    int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        int sum = root->val + left + right;
        sum = max(sum, root->val + max(left, right));
        sum = max(sum, root->val);
        mv = max(mv, sum);
        return sum;
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return mv;
    }
};
