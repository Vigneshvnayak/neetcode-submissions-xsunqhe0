class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0, top = 0;
        int right = matrix[0].size();
        int bottom = matrix.size();
        vector<int> res;
        while (left < right && top < bottom) {
            for (int i = left; i < right; i++) {
                res.push_back(matrix[top][i]);
            }
            top++;
            for (int i = top; i < bottom; i++) {
                res.push_back(matrix[i][right - 1]);
            }
            right--;
            if (!(left < right && top < bottom)) {
                break;
            }
            for (int i = right - 1; i >=left; i--) {
                res.push_back(matrix[bottom - 1][i]);
            }
            bottom--;
            for (int i = bottom - 1; i >= top; i--) {
                res.push_back(matrix[i][left]);
            }
            left++;
        }
        return res;
    }
};
