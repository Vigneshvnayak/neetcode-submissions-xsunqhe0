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
    unordered_set<int> s;
    void dfs(TreeNode* root, int target) {
        if (!root) return;
        s.insert(target - root->val);
        dfs(root->left, target);
        dfs(root->right, target);
        return;
        
    }
    bool is_present(TreeNode* root) {
        if (!root) return false;
        if (s.count(root->val)) return true;
        return is_present(root->left) || is_present(root->right);
    }
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        dfs(root1, target);
        return is_present(root2);
    }
};
