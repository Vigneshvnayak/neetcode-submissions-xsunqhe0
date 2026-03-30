class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       int n = nums.size();
       int l = 0, zeros = 0, res = 0;
       for (int r = 0; r < n; r++) {
            if (!nums[r]) zeros++;
            while (zeros > k) {
                if (!nums[l]) zeros--;
                l++;
            }
            res = max(res, r - l + 1);
       }
       return res;
    }
};