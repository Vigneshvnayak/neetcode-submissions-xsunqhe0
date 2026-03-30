class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       for (int i=0; i<nums.size(); i++) {
            auto f = find(nums.begin(), nums.end(), nums[i]);
            if ((f - nums.begin()) != i) {
                return nums[i];
            }
        }
       return nums[0];
    }
};
