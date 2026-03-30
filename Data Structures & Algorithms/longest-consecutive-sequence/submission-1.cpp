class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       int res = 0;
       unordered_map<int, int> mp;
       int minv = INT_MAX;
       int maxv = INT_MIN;
       for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = 1;
            minv = min(minv, nums[i]);
            maxv = max(maxv, nums[i]);
       }
       cout << minv << maxv << endl;
       for (int i = minv; i <= maxv; i++) {
            if (mp.count(i) > 0) {
                if (mp.count(i - 1) > 0) {
                    mp[i] += mp[i - 1];
                    res = max(res, mp[i]);
                }
            }
       }
       return res;
    }
};
