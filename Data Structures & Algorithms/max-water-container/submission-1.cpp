class Solution {
public:
    int maxArea(vector<int>& a) {
       int val = INT_MIN;
       int l =0;
       int r = a.size() - 1;
       while (l < r) {
        if (a[l] <= a[r]) {
            val = max(val, a[l] * (r-l));
            l++;
        } else {
            val = max(val, a[r] * (r-l));
            r--;
        }
       }
       return val;
    }
};
