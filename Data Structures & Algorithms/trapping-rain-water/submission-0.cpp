class Solution {
public:
    int trap(vector<int>& height) {
       int s = height.size();
       vector<int> val(s, 0);
       int maxl = height[0];
       int maxr = height[s-1];
       int res = 0;
       for (int i=0; i<s; i++) {
        maxl = max(maxl, height[i]);
        val[i] = maxl;
       }
       for (int i = s-1; i>=0; i--) {
        maxr = max(maxr, height[i]);
        val[i] = min(val[i], maxr) - height[i];
        if (val[i] > 0) {
            res += val[i];
        }
       }
       return res;
    }
};
