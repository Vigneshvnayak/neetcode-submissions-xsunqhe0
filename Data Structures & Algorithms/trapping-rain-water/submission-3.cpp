class Solution {
public:
    int trap(vector<int>& height) {
       int s = height.size();
       vector<int> val(s, 0);
       int mv = height[s-1];
       val[0] = height[0];
       int res = 0;
       for (int i=1; i < s; i++) {
        val[i] = max(height[i], val[i-1]);
       }
       for(int i=s-2; i>=0; i--) {
        mv = max(mv, height[i]);
        int temp = (min(mv, val[i]) - height[i]);
        if (temp > 0) {
            res += temp;
        }
       }
      return res;
    }
};
