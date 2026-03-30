class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int l=0;
        int res = INT_MIN;
        for (int r=0; r < s.size(); r++) {
            if (!st.count(s[r])) {
                st.insert(s[r]);
            } else {
                res = max(res,  r - l);
                st.clear();
                st.insert(s[r]);
                l = r;
            }
        }
        return res;
    }
};
