class Solution {
public:
    bool isAnagram(string s, string t) {
       unordered_set<char> st;
       for (char c : s) {
        st.insert(c);
       }
       for (char c : t) {
        if (st.count(c) == 0) {
           return false; 
        }
       }
       return true;
    }
};
