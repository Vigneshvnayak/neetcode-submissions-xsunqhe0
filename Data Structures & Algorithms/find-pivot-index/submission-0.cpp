class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       vector<int> prefix_sum(nums.begin(), nums.end());
       for (int i = 1; i < nums.size(); i++) {
            prefix_sum[i] += prefix_sum[i - 1];
       }
       prefix_sum.insert(prefix_sum.begin(), 0);
       int n = prefix_sum.size();
       for (int i = 1; i < n; i++) {
            if (prefix_sum[i - 1] == (prefix_sum[n - 1] - prefix_sum[i])) {
                return i - 1;
            }
       }
       return -1;
    }
};