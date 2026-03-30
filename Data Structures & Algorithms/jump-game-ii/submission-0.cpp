class Solution {
public:
    int jump(vector<int>& nums) {
        int minindex = nums.size() - 1;
        int target = nums.size() - 1;
        vector<int> a(nums.size(), -1);
        a[nums.size()-1] = 0;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= target) {
                a[i] = a[target] + 1;
                minindex = i;
            }else if (i + nums[i] >= minindex) {
                a[i] = a[minindex] + 1;
            } else {
                int temp = i + nums[i];
                while (temp > i && a[temp] == -1) {
                    temp--;
                }
                if (temp > i) {
                    a[i] = a[temp] + 1;
                }
            }
        }
        return a[0];
    }
};
