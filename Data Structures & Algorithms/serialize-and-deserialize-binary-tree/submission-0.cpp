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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       if (!root) {
        return "N";
       }
       string res;
       queue<TreeNode*>  q;
       q.push(root);
       while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (!node) {
                res += "N,";
            } else {
                res += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
       }
       return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       queue<TreeNode*> q;
       stringstream ss(data);
       string token;
       getline(ss, token, ',');
       if (token == "N") {
            return NULL;
       }
       TreeNode* node = new TreeNode(stoi(token));
       q.push(node);
       while (getline(ss, token, ',')) {
            TreeNode* node = q.front();
            q.pop();
            if (token != "N") {
                node->left = new TreeNode(stoi(token));
                q.push(node->left);
            }
            getline(ss, token, ',');
            if (token != "N") {
               node->right = new TreeNode(stoi(token));
               q.push(node->right);
            }
       }
       return node;
    }
};
