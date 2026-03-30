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
    TreeNode* findroot(TreeNode* root, TreeNode* k) {
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }
        while (k && !q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (cur->val == k->val) {
                return cur;
            }
            if (cur->left) {
                q.push(cur->left);
            }
            if (cur->right) {
                q.push(cur->right);
            }
        }
        return NULL;
    }
    bool dfs(TreeNode* nr, TreeNode* sr) {
        if(!nr && !sr) {
            return true;
        }
        if (!nr || !sr) {
            return false;
        }
        if (nr->val != sr->val) {
            return false;
        }
        return (dfs(nr->left, sr->left) && dfs(nr->right, sr->right));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       TreeNode* nr = findroot(root, subRoot);
       if (!nr) {
        return false;
       }
       printf("%d\n", nr->val);
       return dfs(nr, subRoot);
    }
};
