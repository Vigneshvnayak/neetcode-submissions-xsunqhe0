class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (mp.count(numbers[i])) {
                return {numbers[mp[numbers[i]]], numbers[i]};
            }
            int d = target - numbers[i];
            mp[d] = i;
        }
        return {};
    }
};
