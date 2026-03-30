class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> res(nums.begin(), nums.end()); 
        int sz = res.size();
        for (int i = 0; i < sz; i++) {
            res.push_back(nums[i]);
        }
        return res;
    }
};