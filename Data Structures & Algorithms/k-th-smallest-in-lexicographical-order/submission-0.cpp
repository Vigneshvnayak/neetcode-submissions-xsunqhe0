class Solution {
public:
    int findKthNumber(int n, int k) {
       map<char, vector<int>> mp; 
       for (int i = 1; i <= n; i++) {
            string s = to_string(i);
            mp[s[0]].push_back(i);
       }
       int val = 0;
       int count = 0;
       for (auto [key, value] : mp) {
            for (int i : value) {
                count++;
                if (count == k) {
                    return i;
                }
            }
       }
       return 0;
    }
};