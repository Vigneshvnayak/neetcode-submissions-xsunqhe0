class Solution {
public:
    bool verify(vector<int>& po, int &i, int minval, int maxval) {
        if (i == po.size()) {
            return true;
        }
        int val = po[i];
        if (val <= minval || val >= maxval) {
            return false;
        }
        i++;
        bool left = verify(po, i, minval, val);
        bool right = verify(po, i, val, maxval);
        return left || right;
    }
    bool verifyPreorder(vector<int>& preorder) {
       int i = 0;
       return verify(preorder, i, INT_MIN, INT_MAX);
    }
};
