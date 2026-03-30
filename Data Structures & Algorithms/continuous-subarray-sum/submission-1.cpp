class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
       int n = nums.size(); 
       unordered_map<int, int> mp;
       mp[0] = -1;
       int sum = 0;
       for (int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = sum % k;
            if (!mp.count(rem)) {
                mp[rem] = i;
            } else if (i - mp[rem] >= 2) {
                return true;
            }
        }
       return false;
    }
};