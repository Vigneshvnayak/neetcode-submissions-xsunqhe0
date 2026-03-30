class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        while (k > 0) {
            int t = nums.back();
            nums.pop_back();
            nums.insert(nums.begin(), t);
            k--;
        }
        return;
    }
};