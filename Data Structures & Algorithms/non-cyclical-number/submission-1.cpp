class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        int temp1 = n;
        while (true) {
            if (temp1 == 1) {
                break;
            }
            int cal = 0;
            while (temp1) {
                int rem = temp1 % 10;
                cal = cal + pow(rem, 2);
                temp1 = temp1 / 10;
            }
            temp1 = cal;
            if (s.count(temp1)) {
                return false;
            }
            s.insert(temp1);
        }
        return true;
    }
};
