class Solution {
public:
    bool isValid(string s) {
       unordered_map<char, char> mp = {
        {'}', '{'},
        {')', '('},
        {']', '['}
       };
       stack<char> st;
       int i = 0;
       while (i < s.length()) {
            if (mp.count(s[i]) > 0) {
                if (st.empty() || st.top() != mp[s[i]]) {
                    return false;
                } else {
                    st.pop();
                }
            } else {
                st.push(s[i]);
            }
            i++;
       }
       return (st.empty()) ? true : false; 
    }
};
