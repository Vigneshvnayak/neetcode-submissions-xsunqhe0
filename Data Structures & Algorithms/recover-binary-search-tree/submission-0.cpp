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
    void dfs(TreeNode* root, vector<TreeNode*>& arr) {
        if (!root) return;
        dfs(root->left, arr);
        arr.push_back(root);
        dfs(root->right, arr);
        return;
    }
    void recoverTree(TreeNode* root) {
       vector<TreeNode*> arr;
       dfs(root, arr);
       TreeNode* first = NULL;
       TreeNode* second = NULL;
       int n = arr.size();
       for (int i = 0; i < n - 1; i++) {
            if (arr[i]->val > arr[i + 1]->val) {
                second = arr[i + 1];
                if (!first) {
                    first = arr[i];
                } else {
                    break;
                }
            }
       }
       swap(first->val, second->val);
       return;
    }
};