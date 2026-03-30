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
    int closest = 0;
    void dfs(TreeNode* root, double target) {
        if (!root) return;
        if (abs(target - (double)root->val) < abs(target - (double)closest)) {
            closest = root->val;
        }
        if ((double)root->val <= target) {
            dfs(root->left, target);
        } else {
            dfs(root->right, target);
        }
        return;
    }
    int closestValue(TreeNode* root, double target) {
       dfs(root, target);
       return closest;
    }
};
