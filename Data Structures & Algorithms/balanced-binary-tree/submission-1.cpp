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
    vector<int> height(TreeNode* root) {
        if (!root) {
            return {1,0};
        }
        vector<int> left = height(root->left);
        vector<int> right = height(root->right);
        int balance = (left[0] == 1 && right[0] == 1 && 
         abs(left[1] - right[1]) <= 1) ? 1 : 0; 
        return {balance ? 1 : 0 , (max(left[1], right[1]) + 1)};
    }
    bool isBalanced(TreeNode* root) {
        return height(root)[0];
    }
};
