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
    void dfs(TreeNode* root, vector<TreeNode*>& inorder) {
        if (!root) return;
        dfs(root->left, inorder);
        inorder.push_back(root);
        dfs(root->right, inorder);
        return;
    }
    void recoverTree(TreeNode* root) {
       if (!root) return;
       vector<TreeNode*> inorder; 
       dfs(root, inorder);
       TreeNode* first = NULL;
       TreeNode* second = NULL;
       for (int i = 0; i < inorder.size() - 1; i++) {
            if (inorder[i + 1]->val < inorder[i]->val) {
                second = inorder[i + 1];
                if (!first) {
                    first = inorder[i];
                }
            }
       }
       swap(first->val, second->val);
       return;
    }
};