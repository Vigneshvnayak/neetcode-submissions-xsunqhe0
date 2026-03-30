class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int, int> mp;
       vector<int> op;
       for (int i=0; i<nums.size(); i++) {
        if (mp.count(nums[i]) == 0) {
           mp[target - nums[i]] = i;
        } else {
            op.push_back(mp[target - nums[i]]);
            op.push_back(i);
        }
       } 
       return op;
    }
};
