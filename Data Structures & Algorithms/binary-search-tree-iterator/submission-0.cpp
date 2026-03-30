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
class BSTIterator {
public:
    vector<int> arr;
    int sz;
    int i;
    BSTIterator(TreeNode* root) {
       i = -1;
       dfs(root, arr);
       sz = arr.size();
    }
    void dfs(TreeNode* root, vector<int>& arr) {
        if (!root) return;
        dfs(root->left, arr);
        arr.push_back(root->val);
        dfs(root->right, arr);
        return;
    }
    int next() {
        i++;
        return arr[i];
    }
    
    bool hasNext() {
       if (i + 1 < sz)  return true;
       return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */