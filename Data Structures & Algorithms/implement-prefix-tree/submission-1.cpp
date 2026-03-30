class PrefixNode {
public:
    bool word;
    unordered_map<char, PrefixNode*> child;

    PrefixNode() {
        word = false;
    }
};
class PrefixTree {
public:
    PrefixNode *root;
    PrefixTree() {
       root = new PrefixNode();
    }
    
    void insert(string word) {
       PrefixNode* cur = root; 
       for (char c : word) {
            if (!cur->child.count(c)) {
                cur->child[c] = new PrefixNode();
            }
            cur = cur->child[c];
       }
       cur->word = true;
    }
    
    bool search(string word) {
        PrefixNode* cur = root;
        for (char c : word) {
            if (cur->child.count(c) > 0) {
                cur = cur->child[c];
            } else {
                return false;
            }
        }
        return cur->word;
    }
    
    bool startsWith(string prefix) {
        PrefixNode* cur = root; 
        for (char c : prefix) {
            if (cur->child.count(c) > 0) {
                cur = cur->child[c];
            } else {
                return false;
            }
        }
        return true;
    }
};
