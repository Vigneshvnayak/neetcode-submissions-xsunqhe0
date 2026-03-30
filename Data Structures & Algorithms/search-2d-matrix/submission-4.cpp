class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() - 1;
        int n = matrix[0].size();
        int idx = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (target < matrix[mid][0]) {
               r = mid - 1;
            } else if (target > matrix[mid][n - 1]) {
               l = mid + 1;
            } else {
                idx = mid;
                break;
            }
        }
        l = 0,  r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (target == matrix[idx][mid]) {
                return true;
            } else if (target > matrix[idx][mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
};
