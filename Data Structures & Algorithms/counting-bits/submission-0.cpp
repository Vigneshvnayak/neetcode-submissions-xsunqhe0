class Solution {
public:
    vector<int> countBits(int n) {
       vector<int> res;
       for (int i=0; i<=n; i++) {
        int c = 0;
        int temp = i;
        while (temp > 0) {
            if (temp & 1) {
                c++;
            }
            temp = temp >> 1;
        }
        res.push_back(c);
       }
       return res;
    }
};
