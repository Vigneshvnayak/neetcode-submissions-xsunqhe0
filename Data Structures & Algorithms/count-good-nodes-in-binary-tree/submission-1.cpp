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
    int count = 0;
    void dfs(TreeNode* root, int maxv) {
        if (!root) {
            return;
        }
        if (root->val >= maxv) {
            count++;
            maxv = root->val;
        }
        dfs(root->left, maxv);
        dfs(root->right, maxv);
    }
    int goodNodes(TreeNode* root) {
       dfs(root, root->val);
       return count;
    }
};
