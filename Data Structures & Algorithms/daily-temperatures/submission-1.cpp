class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> stk;
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            if (stk.empty()) {
                stk.push_back(i);
            } else {
                while (!stk.empty() && temperatures[stk.back()] < temperatures[i]) {
                    int number = i - stk.back();
                    res[stk.back()] = number;
                    stk.pop_back();
                }
                stk.push_back(i);
            }
        }
        return res;
    }
};
