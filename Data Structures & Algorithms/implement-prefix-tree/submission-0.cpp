class TrieNode {
public:
    unordered_map<char, TrieNode*> child;
    bool word;
    TrieNode() {
        word = false;
    }
};
class PrefixTree {
    TrieNode* root; 
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;       
        for (char c : word) {
            if (cur->child.count(c) == 0) {
                cur->child[c] = new TrieNode();
            }
            cur = cur->child[c];
        }
        cur->word = true;
    }
    
    bool search(string word) {
       TrieNode* cur = root; 
       for (char c : word) {
        if (cur->child.count(c) == 0) {
            return false;
        }
        cur = cur->child[c];
       }
       return cur->word;
    }
    
    bool startsWith(string prefix) {
        TrieNode*  cur = root;
        for (char c : prefix) {
            if (cur->child.count(c) == 0) {
                return false;
            }
            cur = cur->child[c];
        }
        return true;
    }
};
