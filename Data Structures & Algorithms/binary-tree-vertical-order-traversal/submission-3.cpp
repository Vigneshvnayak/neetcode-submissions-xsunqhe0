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
    vector<vector<int>> verticalOrder(TreeNode* root) {
       if (!root) return {};
       vector<vector<int>> res;
       queue<pair<TreeNode*, int>> q;
       map<int, vector<int>> mp;
       q.push({root, 0});
       while (!q.empty()) {
            auto [cur, key] = q.front();
            q.pop();
            mp[key].push_back(cur->val);
            if (cur->left) {
                q.push({cur->left, key - 1});
            }
            if (cur->right) {
                q.push({cur->right, key + 1});
            }
       }
       for (auto [key, value] : mp) {
            res.push_back(value);
       }
       return res;
    }
};