class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
       int n = nums.size();
       priority_queue<int> pq; 
       int l = 0, r = n - 1;
       while (l < r) {
            pq.push(abs(nums[l] - nums[r]));
            if (pq.size() > p) {
                pq.pop();
            }
            if (nums[l] >= nums[r]) {
                l++;
            } else {
                r--;
            }
       }
       return pq.top();
    }
};