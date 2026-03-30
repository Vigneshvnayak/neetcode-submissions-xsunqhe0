class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       vector<int> res; 
       for (int n : nums) {
            if (n != val) {
                res.push_back(n);
            }
       }
       return res;
    }
};