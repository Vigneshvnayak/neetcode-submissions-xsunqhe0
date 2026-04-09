class Solution {
public:
    string addBoldTag(string s, vector<string>& words) {
        int n = s.length();
        vector<bool> check(n, false);
        for (string word : words) {
            int start = s.find(word);
            while (start != string::npos) {
                for (int i = start; i < start + word.size(); i++) {
                    check[i] = true;
                }
                start = s.find(word, start + 1);
            }
        }
        string res = "";
        for (int i = 0; i < n; i++) {
            if (check[i] && (i == 0 || !check[i - 1])) {
                res += "<b>";
            }
            res += s[i];
            if (check[i] && (i == n - 1|| !check[i + 1])) {
                res += "</b>";
            }
        }
        return res;
    }
};
