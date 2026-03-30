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
public:
    Node* cloneGraph(Node* node) {
       if (!node) {
        return NULL;
       }
       unordered_map<Node*, Node*> mp;
       queue<Node*> q;
       mp[node] = new Node(node->val);
       q.push(node);
       while (!q.empty()) {
          Node * n = q.front();
          q.pop();
          for(Node* i : n->neighbors) {
            if (!mp.count(i)) {
                mp[i] = new Node(i->val);
                q.push(i);
            }
            mp[n]->neighbors.push_back(mp[i]);
          }
       }
       return mp[node];
    }
};
