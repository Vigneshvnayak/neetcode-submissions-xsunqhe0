class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < n) {
            int next = (i + 1) % n;
            if (nums[i] == nums[next]) {
                i += 2;
            } else {
                res.push_back(nums[i]);
                i += 1;
            }
        }
        return res;
    }
};