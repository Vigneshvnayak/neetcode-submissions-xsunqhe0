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
    vector<int> rightSideView(TreeNode* root) {
       if (!root) return {};
       vector<int> res; 
       queue<TreeNode*> q;
       q.push(root);
       while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            res.push_back(cur->val);
            if (cur->right) {
                q.push(cur->right);
            } else if (cur->left) {
                q.push(cur->left);
            }
       }
       return res;
    }
};
