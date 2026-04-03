/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* root, vector<TreeNode*>& stk, int target) {
        if (!root) return false;
        if (root->val == target) {
            stk.push_back(root);
            return true;
        }
        bool left = dfs(root->left, stk, target);
        bool right = dfs(root->right, stk, target);
        if (left || right) stk.push_back(root);
        return left || right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if (!root) return NULL;
       vector<TreeNode*> stkp, stkq;
       dfs(root, stkp, p->val);
       dfs(root, stkq, q->val);
       int i = stkp.size() - 1;
       int j = stkq.size() - 1;
       TreeNode* res = NULL;
       while (i >= 0 && j >= 0 && stkp[i] == stkq[j]) {
            res = stkp[i];
            i--;
            j--;
       }
       return res;
    }
};