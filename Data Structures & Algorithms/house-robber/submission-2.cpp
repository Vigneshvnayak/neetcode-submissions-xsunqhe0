class Solution {
public:
    int rob(vector<int>& nums) {
       int size = nums.size();
       vector<int> index(size, 0);
       if (size == 1) {
        return nums[0];
       }
       if (size == 2) {
        return max(nums[0], nums[1]);
       }
       if (size == 3) {
        return max(nums[0] + nums[2], nums[1]);
       }
       index[size-1] = nums[size-1];
       index[size-2] = nums[size-2];
       int m = index[size-1];
       int j = size-1;
       for (int i = size-3; i>=0; i--) {
            index[i] = nums[i] + m;
            j--;
            m = max(m, index[j]);
       }
       return max(index[0],m);
    }
};
