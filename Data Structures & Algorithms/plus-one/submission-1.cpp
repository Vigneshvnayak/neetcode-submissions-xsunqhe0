class Solution {
public:
    vector<int> plusOne(vector<int>& nums) {
       vector<int> res;
       int carry = 0;
       int size = nums.size();
       res.push_back((nums[size-1] + 1) % 10);
       carry = (nums[size-1] + 1) / 10;
       for (int i=size-2; i>=0; i--) {
            int sum = carry + nums[i];
            carry = sum/10;
            res.push_back(sum % 10);
       }
       if (carry > 0) {
            res.push_back(carry);
       }
       reverse(res.begin(), res.end());
       return res;
    }
};
