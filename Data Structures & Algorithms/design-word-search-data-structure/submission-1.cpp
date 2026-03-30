class TrieNode {
public:
    vector<TrieNode*> child;
    bool word;
    TrieNode() : child(26, nullptr) , word(false) {}
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
       root = new TrieNode();
    }
    
    void addWord(string word) {
       TrieNode* cur = root;
       for (char c : word) {
        if (cur->child[c - 'a'] == nullptr) {
            cur->child[c - 'a'] = new TrieNode();
        }
        cur = cur->child[c -'a'];
       }
       cur->word = true;
    }
    
    bool search(string word) {
       return dfs(word, 0, root);
    }
private:
    bool dfs(string word, int idx, TrieNode* root) {
        TrieNode* cur = root;
        for (int i=idx; i < word.size(); i++) {
            char c = word[i];
            if (c == '.') {
                for (TrieNode* d : cur->child) {
                   if (d && dfs(word, i+1, d)) {
                    return true;
                   }
                }
                return false;
            } else {
                if (cur->child[c - 'a'] == nullptr) {
                    return false;
                }
                cur = cur->child[c - 'a'];
            }
        }
        return cur->word;
    }
};

