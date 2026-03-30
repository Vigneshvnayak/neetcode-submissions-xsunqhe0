class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
       if (k == 0) return false;
       int n = nums.size(); 
       unordered_map<int, int> remainder;
       remainder[0] = -1;
       int sum = 0;
       for (int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = sum % k;
            if (!remainder.count(rem)) {
                remainder[rem] = i;
            } else if (i - remainder[rem] >= 2) {
                return true;
            }
        }
       return false;
    }
};