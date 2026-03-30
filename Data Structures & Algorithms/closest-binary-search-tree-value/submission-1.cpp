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
    void dfs(TreeNode* root, double target, int& closest) {
        if(!root) return;
        if (abs(root->val - target) < abs(closest - target)) {
            closest = root->val;
        } else if (abs(root->val - target) == abs(closest - target)) {
            if (root->val < closest) {
                closest = root->val;
            }
        }
        if (target < root->val) {
            return dfs(root->left, target, closest);
        } else {
            return dfs(root->right, target, closest);
        }
        return;
    }
    int closestValue(TreeNode* root, double target) {
       int closest = root->val;
       dfs(root, target, closest);
       return closest;
    }
};
