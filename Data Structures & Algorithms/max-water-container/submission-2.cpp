class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;        
        int r = heights.size() - 1;
        int water = 0;
        while (l < r) {
            water = max(water, min(heights[l], heights[r]) * (r - l));
            if (heights[l] <= heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return water;
    }
};
