class Solution {
public:
    int maxArea(vector<int>& heights) {
       int res = 0;
       int  i = 0, j = heights.size() - 1;
       while (i < j) {
        int temp = 0;
        if (heights[i] <= heights[j]) {
            temp = heights[i] * (j - i++);
        }else if (heights[i] > heights[j]) {
            temp = heights[j] * ((j--) - i);
        }
        res = max(res, temp);
       }
       return res;
    }
};
