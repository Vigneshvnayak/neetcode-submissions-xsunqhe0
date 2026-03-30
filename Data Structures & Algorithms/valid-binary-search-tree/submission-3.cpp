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
    bool helper(TreeNode* node, int minval, int maxval) {
        if(!node) {
            return true;
        }
        if (node->val <= minval || node->val >= maxval) {
            return false;
        }
        return helper(node->left, minval, node->val) && helper(node->right, node->val, maxval);
    }
    bool isValidBST(TreeNode* root) {
       return helper(root, INT_MIN, INT_MAX);
    }
};
