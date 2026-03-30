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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       queue<TreeNode*> que;
       if (root) {
        que.push(root);
       }
       while (!que.empty()) {
        TreeNode* cur = que.front();
        que.pop();
        if (p->val < cur->val && q->val < cur->val) {
            que.push(cur->left);
        }else if (p->val > cur->val && q->val > cur->val) {
            que.push(cur->right);
        } else {
            return cur;
        }
       }
       return root;
    }
};
