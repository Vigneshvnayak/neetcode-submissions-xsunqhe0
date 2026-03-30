class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map <char, char> mp;
        mp['}'] = '{';
        mp[')'] = '(';
        mp[']'] = '[';
        if (s.size() == 0) {
            return true;
        }
        for (char c : s) {
            if (mp.count(c) > 0) {
                if (!st.empty() && st.top() == mp[c]) {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                st.push(c);
            }
        }
        return st.empty();
    }
};
