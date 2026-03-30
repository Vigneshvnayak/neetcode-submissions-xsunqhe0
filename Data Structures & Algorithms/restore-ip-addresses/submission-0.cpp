class Solution {
public:
    vector<string> dp (string &s, int index, int dots, unordered_map<string, vector<string>> &memo) {
        string key = to_string(index) + "," + to_string(dots);
        vector<string> res;
        if (memo.count(key)) {
            return memo[key];
        }
        if (index == s.length() && dots == 4) {
            res.push_back("");
            return res;
        }
        if (dots >= 4) {
            return res;
        }
        for (int len = 1; len <=3 && index + len <= s.size(); len++) {
            string octet = s.substr(index, len);
            if (octet[0] == '0' && octet.length() > 1) {
                continue;
            }
            int ioctet = stoi(octet);
            if (ioctet >= 0 && ioctet <= 255) {
                vector<string> next = dp(s, index + len, dots + 1, memo); 
                for (string &tail : next) {
                    res.push_back(octet + (tail.empty() ? "" : ".") + tail);                         
                }
            }
        }
        memo[key] = res;
        return res;
    }
    vector<string> restoreIpAddresses(string s) {
       unordered_map<string, vector<string>> memo;
       return dp(s, 0, 0, memo);
    }
};