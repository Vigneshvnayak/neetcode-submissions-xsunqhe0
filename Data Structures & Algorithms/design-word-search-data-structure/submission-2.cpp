class TrieNode {
public:
    unordered_map<char, TrieNode*> child;
    bool ispresent;

    TrieNode() {
        ispresent = false;
    }
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
            if (!cur->child.count(c)) {
                cur->child[c] = new TrieNode();
            }
            cur = cur->child[c];
       }
       cur->ispresent = true;
    }
    bool search(string word) {
        TrieNode* cur = root;
        return dfs(0, cur, word);
    }
    bool dfs(int idx, TrieNode* ch, string word) {
       TrieNode* cur = ch;
       for (int i = idx; i < word.length(); i++) {
            if (word[i] == '.') {
                for (auto ch : cur->child) {
                    if (ch.second && dfs(i + 1, ch.second, word)) {
                        return true;
                    }
                }
                return false;
            } else {
                if (!cur->child.count(word[i])) {
                    return false;
                }
                cur = cur->child[word[i]];
            }
       }
       return cur->ispresent;
    }
};
