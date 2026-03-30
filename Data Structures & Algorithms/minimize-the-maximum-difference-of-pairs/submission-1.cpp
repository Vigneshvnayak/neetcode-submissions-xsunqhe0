class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
       int n = nums.size();
       sort(nums.begin(), nums.end());
       int l = 0, r = nums.back() - nums.front();
       while (l < r) {
            int mid = l + (r - l) / 2;
            int count = 0;
            for (int i = 1; i < n; ) {
                if(nums[i] - nums[i - 1] <= mid) {
                    count++;
                    i += 2;
                } else {
                    i++;
                }
            }
            if (count >= p) {
                r = mid;
            } else {
                l = mid + 1;
            }
       }
       return l;
    }
};