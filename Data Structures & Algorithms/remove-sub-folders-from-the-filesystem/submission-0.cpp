class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
       int n = folder.size();
       vector<string> res;
       sort(folder.begin(), folder.end());
       for (string f : folder) {
            if (res.empty() || f.find(res.back() + '/') != 0) {
                res.push_back(f);
            }
       }
       return res;
    }
};