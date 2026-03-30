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
int dfs(TreeNode* root, int& mv) {
    if (!root) {
        return 0;
    }
    int l = dfs(root->left, mv);
    int r = dfs(root->right, mv);
    mv = max(mv, l + r);
    return 1 + max(l, r);
}
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int mv = 0;
        dfs(root, mv);
        return mv;
    }
};
