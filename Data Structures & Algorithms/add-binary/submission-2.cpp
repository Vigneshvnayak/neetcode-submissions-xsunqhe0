class Solution {
public:
    string addBinary(string a, string b) {
       int i = a.length() - 1;
       int j = b.length() - 1;
       string res = "";
       int carry = 0;
       while (i >= 0 || j >= 0) {
            int sum = carry;
            sum += (i >= 0) ? (a[i--] - '0') : 0;
            sum += (j >= 0) ? (b[j--] - '0') : 0;
            res = res + to_string(sum % 2);
            carry = sum / 2;
       }
       reverse(res.begin(), res.end());
       return res;
    }
};