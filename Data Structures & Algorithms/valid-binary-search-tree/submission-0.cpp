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
    bool isValidBST(TreeNode* root) {
       queue<TreeNode*> q;
       if (root) {
        q.push(root);
       }
       while (!q.empty()) {
        TreeNode* r = q.front();
        q.pop();
        if (r->left) {
            if (r->left->val >= r->val) {
                return false;
            }
            q.push(r->left);
        }
        if (r->right) {
            if (r->right->val <= r->val) {
                return false;
            }
            q.push(r->right);
        }
       }
       return true;
    }
};
