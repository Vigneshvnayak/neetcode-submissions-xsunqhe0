class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int n1 = word.length();
        int n2 = abbr.length();
        int i = 0;
        int j = 0;
        int count = 0;
        while (i < n1 && j < n2) {
            if (word[i] == abbr[j]) {
                i++;
                j++;
            } else if (isdigit(abbr[j])) {
                int d = 0; 
                while (j < n2 && isdigit(abbr[j])) {
                    d = d * 10 + abbr[j] - '0';
                    j++;
                }
                if (d > word.size()) {
                    return false;
                }
                while (d > 0) {
                    i++;
                    d--;
                }
            } else {
                return false;
            }
        }
        return true;
    }
};