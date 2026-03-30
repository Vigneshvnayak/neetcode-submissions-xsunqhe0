/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
map<Node*, Node*> otn;
public:
    Node* dfs(Node* node) {
        if (!node) {
            return NULL;
        }
        if (otn.count(node)) {
            return otn[node];
        }
        Node* copy = new Node(node->val);
        otn[node] = copy;
        for (Node* n : node->neighbors) {
            copy->neighbors.push_back(dfs(n));
        }
        return copy;
    }
    Node* cloneGraph(Node* node) {
      return dfs(node);
    }
};
