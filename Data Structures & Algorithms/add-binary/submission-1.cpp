class Solution {
public:
    int btos(string s) {
        int i = s.length() - 1;
        int res = 0;
        while (i >= 0) {
            if (s[i] == '1') {
                res += pow(2, s.length() - 1 - i);
            }
            i--;
        }
        return res;
    }
    string addBinary(string a, string b) {
        int s = 0;
        int x = btos(a);
        int y = btos(b);
        int sum = x + y;
        if (sum == 0) {
            return "0";
        }
        string res = "";
        while (sum > 0) {
            if (sum & 1) {
                res = "1" + res;
            } else {
                res = "0" + res;
            }
            sum = sum >> 1;
        }
        return res;
    }
};