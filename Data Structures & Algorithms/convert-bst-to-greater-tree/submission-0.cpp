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
    TreeNode* dfs(TreeNode* node, TreeNode* newnode, int& sum) {
        if (!node) return NULL;
        if (!newnode) newnode = new TreeNode();
        newnode->right = dfs(node->right, newnode->right, sum);
        sum += node->val;
        newnode->val = sum;
        newnode->left = dfs(node->left, newnode->left, sum);
        return newnode;
    }
    TreeNode* convertBST(TreeNode* root) {
       int sum = 0; 
       TreeNode* newroot = NULL;
       return dfs(root, newroot, sum);
    }
};