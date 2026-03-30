class Solution {
public:
    bool canJump(vector<int>& nums) {
       int sz = nums.size();
       if (sz == 1) {
        return true;
       }
       if (sz == 2) {
        if (nums[0] >= 1) {
            return true;
        }
       }
       int target = sz - 1;
       bool res = false;
       for (int i = sz - 2; i>=0; i--) {
        if (nums[i] + i >= target) {
            target = i;
            res = true; 
        } else {
            res = false;
        }
       }
       return res;
    }
};
