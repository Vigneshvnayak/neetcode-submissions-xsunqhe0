class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        for (int r = 0; r < n; r++) {
            if (nums[r] != 0) {
                nums[l] = nums[r];
                l++;
            }
        }
        for (int i = l; i < n; i++) {
            nums[i] = 0;
        }
        return;
    }
};