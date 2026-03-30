class Solution {
public:
    int rob(vector<int>& nums) {
       int v1, v2;
       int s = nums.size();
       if (s == 1) {
        return nums[0];
       }
       if (s == 2) {
        return max(nums[0], nums[1]);
       }
       vector<int> a(s, 0);
       a[s-2] = nums[s-2];
       a[s-3] = max(nums[s-2], nums[s-3]);
       for (int i=s-4; i>=0; i--) {
        a[i] = max(a[i+1], nums[i] + a[i+2]);
       }
       v1 = a[0];
       a[s-1] = nums[s-1];
       a[s-2] = max(nums[s-2], nums[s-1]);
       for (int i=s-3; i>0; i--) {
        a[i] = max(a[i+1], nums[i] + a[i+2]);
       }
       v2 = a[1];
       return max(v1, v2);
    }
};
