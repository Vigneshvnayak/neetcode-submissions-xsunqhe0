class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int n = height.size();
        vector<int> LR(n, 0);
        LR[0] = height[0];
        int right = 0;
        for (int i = 1; i < n; i++) {
           LR[i] = max(height[i], LR[i-1]);
        }
        for (int i = n - 1; i >= 0; i--) {
            right = max(right, height[i]);
            res += (min(LR[i], right) - height[i]);
        }
        return res;
    }
};
