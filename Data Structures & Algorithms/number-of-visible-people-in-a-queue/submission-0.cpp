class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> res(n, 0);
        vector<int> stk;
        stk.push_back(heights[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            int count = 0;
            while (!stk.empty() && heights[i] > stk.back()) {
               stk.pop_back();
               count++;
            }
            if (!stk.empty()) {
                count++;
            }
            res[i] = count;
            stk.push_back(heights[i]);
        }
        return res;
    }
};