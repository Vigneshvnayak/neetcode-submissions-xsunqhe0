class Solution {
public:
    bool isPowerOfTwo(int n) {
       float test = n; 
       while (test > 1.0) {
            test /= 2.0;
       }
       return test < 1.0 ? false : true;
    }
};