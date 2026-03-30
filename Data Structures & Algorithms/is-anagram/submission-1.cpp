class Solution {
public:
    bool isAnagram(string s, string t) {
       vector<int> c(26,0);
       for(char ca : s) {
        c[ca - 'a']++;
       }
       for(char ca : t) {
        c[ca - 'a']++;
       }
       for(int i=0; i<26; i++) {
        if (c[i] % 2 == 1) {
            return false;
        }
       }
       return true;
    }
};
