class Solution {
public:
    string minRemoveToMakeValid(string s) {
       int n = s.length();
       stack<int> st;
       unordered_set<int> skip;
       string res = "";
       for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')'){
                if (st.empty()) {
                    skip.insert(i);
                } else {
                    st.pop();
                }
            }
       }
       while (!st.empty()) {
            skip.insert(st.top());
            st.pop();
       }
       for (int i = 0; i < n; i++) {
            if (!skip.count(i)) {
                res += s[i];
            }
       }
       return res;
    }
};
