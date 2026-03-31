class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> scount, tcount;
        for (char c : t) {
            tcount[c]++;
        }
        int l = 0, start = 0;
        int maxlen = INT_MAX, match = 0, need = tcount.size();
        for (int r = 0; r < s.length(); r++) {
            scount[s[r]]++;
            if (tcount.count(s[r]) && tcount[s[r]] == scount[s[r]]) {
                match++;
            }
            while (need == match) {
                if (r - l + 1 < maxlen) {
                    maxlen = r - l + 1;
                    start = l;
                }
                scount[s[l]]--;
                if (tcount.count(s[l]) && tcount[s[l]] > scount[s[l]]) {
                    match--;
                }
                l++;
            }
        }
        return (maxlen == INT_MAX) ? "" : s.substr(start, maxlen);
    }
};
