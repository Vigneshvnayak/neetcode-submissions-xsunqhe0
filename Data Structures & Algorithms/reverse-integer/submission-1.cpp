class Solution {
public:
    int reverse(int x) {
       int neg = x < 0; 
       string s = to_string(x);
       std::reverse(s.begin(), s.end());
       long long rev = stoll(s);
       if (neg) {
            rev = -1 * rev;
       }
       if (rev < INT_MIN || rev > INT_MAX) {
            return 0;
       }
       return static_cast<int>(rev);
    }
};
