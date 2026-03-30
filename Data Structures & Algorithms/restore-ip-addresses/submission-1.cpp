class Solution {
public:
    void dp(string &s, int index, int dots, string path, vector<string> &res) {
        if (dots == 4 && index == s.length()) {
            res.push_back(path.substr(0, path.length() - 1));
        }
        if (dots >= 4) {
            return;
        }
        for (int len = 1; len <= 3 && index + len <= s.length(); len++) {
            string octet = s.substr(index, len);
            if ((octet[0] == '0' && octet.length() > 1) || stoi(octet) > 255) {
                continue;
            }
            dp(s, index + len, dots + 1, path + octet + ".", res);
        }
    }
    vector<string> restoreIpAddresses(string s) {
       vector<string> res; 
       dp(s, 0, 0, "", res);
       return res;
    }
};