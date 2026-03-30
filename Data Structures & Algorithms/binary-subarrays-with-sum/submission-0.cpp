class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0, res = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int diff = sum - goal;
            if (mp.count(diff)) {
                res += mp[diff];
            }
            mp[sum]++;
        }
        return res;
    }
};