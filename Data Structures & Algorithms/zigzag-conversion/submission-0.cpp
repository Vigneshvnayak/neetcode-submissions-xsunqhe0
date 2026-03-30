class Solution {
public:
    string convert(string s, int numRows) {
       if (numRows == 1 || s.length() == numRows) {
            return s;
       }
       vector<string> rows(numRows, "");
       int i = 0, dir = 1;
       for (char c : s) {
            rows[i] += c;
            i += dir;
            if (i == 0 || i == numRows - 1) {
                dir *= -1;
            }
       }
       string res = "";
       for (string r : rows) {
            res += r;
       }
       return res;
    }
};