class Solution {
public:
    bool check(double x, int k, vector<int>& nums) {
        double cur = 0.0, prev = 0.0, min_sum = 0.0;
        for (int i = 0; i < k; i++) {
            cur += nums[i] - x;
        }
        if (cur >= 0) return true;
        for (int i = k; i < nums.size(); i++) {
            cur += nums[i] - x;
            prev += nums[i - k] - x;
            min_sum = min(min_sum, prev);
            if (cur - min_sum >= 0) {
                return true;
            }
        }
        return false;
    }
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double low = *min_element(nums.begin(), nums.end());
        double high = *max_element(nums.begin(), nums.end());
        while (high - low > 1e-5) {
           double mid = low + (high - low) / 2.0;
           if (check(mid, k, nums)) {
                low = mid;
           } else {
                high = mid;
           }
        }
        return low;
    }
};
