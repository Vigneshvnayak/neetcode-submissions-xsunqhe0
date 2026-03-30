class Solution {
public:
    string foreignDictionary(vector<string>& words) {
       int n = words.size();
       unordered_map<char, unordered_set<char>> adj;
       unordered_map<char, int> inorder;
       for (string w : words) {
            for (char c : w) {
                if (adj.find(c) == adj.end()) {
                    adj[c] = unordered_set<char>();
                    inorder[c] = 0;
                }
            }
       }
       for (int k = 0; k < n - 1; k++) {
           string w1 = words[k];
           string w2 = words[k + 1];
           int minlen = min(w1.size(), w2.size());
           if (w1.size() > w2.size()) {
                if (w1.substr(0, minlen) == w2.substr(0, minlen)) {
                    return "";
                }
           }
           int i = 0;
           while (i < minlen && w1[i] == w2[i]) {
                i++;
           }
           if (i < minlen && !adj[w1[i]].count(w2[i])) {
                adj[w1[i]].insert(w2[i]);
                inorder[w2[i]]++;
           }
       }
       queue<char> q;
       for (auto [k, v] : inorder) {
            if (v == 0) {
                q.push(k);
            }
       }
       string res = "";
       while (!q.empty()) {
            char cur = q.front();
            q.pop();
            res += cur;
            for (char next : adj[cur]) {
                if (--inorder[next] == 0) {
                    q.push(next);
                }
            }
       }
       return res.size() != inorder.size() ? "" : res;
    }
};
