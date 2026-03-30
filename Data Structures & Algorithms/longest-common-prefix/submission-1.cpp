class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       string prefix = strs[0];
       for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            int len = min(prefix.size(), strs[i].size());
            while (j < len && prefix[j] == strs[i][j]) {
                j++;
            }
            prefix = prefix.substr(0, j);
       }
       return prefix;
    }
};