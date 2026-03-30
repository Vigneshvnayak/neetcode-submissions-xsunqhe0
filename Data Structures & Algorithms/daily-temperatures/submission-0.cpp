class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack <pair<int,int>> st;
        vector<int> res(temp.size(),0);
        st.push({temp[0], 0});
        for(int i=1; i<temp.size(); i++) {
            while (!st.empty() && temp[i] > st.top().first) {
		        res[st.top().second] = i - st.top().second;
		        st.pop();
            }
            st.push({temp[i], i});
        }
        return res; 
    }
};
