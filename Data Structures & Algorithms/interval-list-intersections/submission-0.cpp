class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
       vector<vector<int>> res; 
       firstList.insert(firstList.end(), secondList.begin(), secondList.end());
       sort(firstList.begin(), firstList.end());
       int n = firstList.size();
       for (int i = 1; i < n; i++) {
            if (firstList[i][0] <= firstList[i - 1][1]) {
                res.push_back({firstList[i][0], min(firstList[i - 1][1], firstList[i][1])});
            }
       }
       return res;
    }
};