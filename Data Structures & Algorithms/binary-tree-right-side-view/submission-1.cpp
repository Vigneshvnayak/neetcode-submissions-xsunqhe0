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
       queue<TreeNode*> q;
       vector<int> op;
       if (root)
            q.push(root);
       while (!q.empty()) {
        int rightest = q.front()->val;
        op.push_back(rightest);
        int len = q.size();
        for (int i=0; i<len; i++) {
            TreeNode* temp = q.front();
            q.pop();
            if (temp->right) {
                q.push(temp->right);
            }
            if (temp->left) {
                q.push(temp->left);
            }
        }
       } 
       return op;
    }
};
