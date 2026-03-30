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
    vector<vector<int>> levelOrder(TreeNode* root) {
       queue<TreeNode*> q;
       vector<vector<int>> op;
       if (root) {
        q.push(root);
       } 
       int level = 0;
       while (!q.empty()) {
        vector<int> t;
        level = q.size();
        for (int i=0; i<level; i++) {
            TreeNode* temp = q.front();
            q.pop();
            t.push_back(temp->val);
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
        op.push_back(t);
       }
       return op;
    }
};
