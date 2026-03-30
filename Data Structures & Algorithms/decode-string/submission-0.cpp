class Solution {
public:
    string decodeString(string s) {
        vector<string> stk;
        for (char c : s) {
            if (c != ']') {
                stk.push_back(string(1, c));
            } else {
                string t1 = "";
                string d1 = "";
                while (!stk.empty() && stk.back() != "[") {
                    t1 = stk.back() + t1;
                    stk.pop_back();
                }
                stk.pop_back();
                while (!stk.empty() && isdigit(stk.back()[0])) {
                    d1 = stk.back() + d1;
                    stk.pop_back();
                }
                int d2 = stoi(d1);
                string t2 = "";
                for (int i = 0; i < d2; i++) {
                    t2 = t1 + t2;
                }
                stk.push_back(t2);
            }
        }
        string res = "";
        for (string t3 : stk) {
            res = res + t3;
        }
        return res;
    }
};