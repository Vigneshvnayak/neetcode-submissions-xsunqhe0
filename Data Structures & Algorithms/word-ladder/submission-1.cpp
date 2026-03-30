class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       unordered_set<string> s(wordList.begin(), wordList.end());
       queue<pair<string, int>> q; 
       q.push({beginWord, 1});
       while (!q.empty()) {
            pair<string, int> t = q.front();
            q.pop();
            string w = t.first;
            int n = t.second;
            if (w == endWord) {
                return n;
            }
            for (int i = 0; i < w.size(); i++) {
                char temp = w[i];
                for (int j = 0; j < 26; j++) {
                    if (('a' + j != temp)) {
                        w[i] = 'a' + j;
                    }
                    if (s.count(w)) {
                        q.push({w, n + 1});
                        s.erase(w);
                    }
                }
                w[i] = temp;
            }
       }
       return 0;
    }
};
