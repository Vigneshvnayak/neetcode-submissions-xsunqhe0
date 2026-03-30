class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
       int l = 0, r = numbers.size()-1;
       while (l < r) {
        int temp = numbers[l] + numbers[r];
        if(temp < target) {
            l++;
        }
        else if (temp > target) {
            r--;
        } else {
            return vector<int> {numbers[l], numbers[r]};
        }
       }
       return vector<int>{};
    }
};
