class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res=0;
        int size = nums.size();
        for (int n : nums) {
            res ^= n;
        }
        for (int i=0; i<=size; i++) {
            res ^= i;
        }
        return res;
    }
};
