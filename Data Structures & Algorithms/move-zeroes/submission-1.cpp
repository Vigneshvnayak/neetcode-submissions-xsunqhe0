class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] != 0) {
                nums[l] = nums[r];
                l++;
            }
        }
        while (l < nums.size()) {
            nums[l] = 0;
            l++;
        }
        return;
    }
};