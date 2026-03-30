class Solution {
public:
    string minWindow(string s, string t) {
       if (t.empty()) return "";
        unordered_map<char, int> countT, countS;
        for (char c : t) {
        	countT[c]++;
        }
        int match = 0;
        int need = countT.size();
        int resl = -1, resr = -1;
        int len = INT_MAX;
        int l= 0;
        for (int r = 0; r < s.size(); r++) {
            countS[s[r]]++;
            if (countT.count(s[r]) && countT[s[r]] == countS[s[r]]) {
                match++;
            }
            while (match == need) {
                if( r - l + 1 < len) {
                    len = r - l + 1;
                    resl = l;
                    resr = r;
                }
                countS[s[l]]--;
                if (countT.count(s[l]) && countT[s[l]] > countS[s[l]]) {
                    match--;
            	}
		        l++;
	        }
        }
        return len == INT_MAX ? "" : s.substr(resl, len);

    }
};
