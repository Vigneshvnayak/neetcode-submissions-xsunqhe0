class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 1) return nums;
        priority_queue<vector<int>> pq;
        vector<int> res;
	    int  l = 0;
	    for (int r = 0; r <= nums.size(); r++) {
		    if (r - l + 1 > k) {
		        int temp = pq.top()[1];
		        while (temp < l) {
			        pq.pop();
                    temp = pq.top()[1];	
	            }
                res.push_back(pq.top()[0]);
                l++;
		    }	
		    pq.push({nums[r], r});	
        }
        return res;
    }
};
