class Solution {
public:
    int rob(vector<int>& nums) {
        nums.push_back(0);
        for (int i = nums.size() - 3; i >= 0; i--) {
            nums[i] = max(nums[i] + nums[i + 2], nums[i + 1]);
        }
        return nums[0];
    }
};
/*
 0  1  2  3  4  5
[2, 9, 8, 3, 6] 0
       i
[16  15  14  6  6]
[                ]
*/

