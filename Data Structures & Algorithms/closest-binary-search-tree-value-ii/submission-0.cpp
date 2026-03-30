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
    void dfs(TreeNode* root, vector<int>& arr) {
        if (!root) return; 
        dfs(root->left, arr);
        arr.push_back(root->val);
        dfs(root->right, arr);
        return;
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
       vector<int> arr; 
       dfs(root, arr);
       int left = 0, right = arr.size() - k;
       while (left < right) {
            int mid = (left + right) / 2;
            if (abs(target - arr[mid]) > abs(target - arr[mid + k])) {
                left = mid + 1;
            } else {
                right = mid;
            }
       }
       return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};
