class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curmax = 1;
	int curmin = 1;
	int mv = INT_MIN;
	for (int i=0; i<nums.size(); i++) {
		int temp = curmax * nums[i];
curmax = max(max(curmax * nums[i], curmin * nums[i]), nums[i]);
curmin = min(min(temp, curmin * nums[i]), 
	nums[i]);
mv = max(mv, curmax); 
}
return mv;

    }
};
