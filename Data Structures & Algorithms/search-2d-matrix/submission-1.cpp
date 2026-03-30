class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int r = matrix.size();
       int c = matrix[0].size();
       int t = 0;
       int b = r - 1;
       while (t <= b) {
        int mid = (t + b) /2;
        if (target > matrix[mid][c-1]) {
            t = mid + 1;
        } else if (target < matrix[mid][0]) {
            b = mid - 1;
        } else {
            break;
        }
       }
       if (t > b) {
        return false;
       }
       int mid = (t + b)/2; 
       int l = 0;
       int h = c-1;
       while (l <= h) {
        int mid2 = l + (h-l)/2;
        if (target > matrix[mid][mid2]) {
            l = mid2 + 1;
        } else if (target < matrix[mid][mid2]) {
            h = mid2 - 1;
        } else {
            return true;
        }
       }
       return false; 
    }
};
