class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int fast = 0, slow = 0;
       while (slow < nums.size()) {
        fast += 2;
        slow += 1;
        if (fast >= nums.size()) {
            fast = fast % nums.size();
        }
        if (nums[fast] == nums[slow] && slow != fast) {
            break;
        }
       }
       return nums[slow];
    }
};
