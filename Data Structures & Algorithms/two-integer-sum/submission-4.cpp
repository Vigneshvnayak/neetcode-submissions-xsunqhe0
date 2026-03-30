class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int, int> mp;
       vector<int> res;
       for(int i=0; i < nums.size(); i++) {
            if (mp.count(nums[i]) > 0) {
                res = {mp[nums[i]], i};
            } else {
                int t = target - nums[i];
                mp[t] = i;
            }
       }
       return res; 
    }
};
