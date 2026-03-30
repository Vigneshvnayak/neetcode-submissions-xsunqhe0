class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       int n = digits.size();
       vector<int> res; 
       int c = 1;
       int s = 0;
       for (int i = n - 1; i >= 0; i--) {
            s = digits[i] + c;
            c = s / 10;
            res.push_back(s % 10);
       }
       if (c) {
            res.push_back(c);
       }
       reverse(res.begin(), res.end());
       return res;
    }
};
