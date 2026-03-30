class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> ns(nums.begin(), nums.end());
       int longest = 0;
       for (int n : ns) {
        if (ns.find(n-1) == ns.end()) {
            int length = 1;
            while (ns.find(n + length) != ns.end()) {
                length++;
            }
            longest = max(length, longest);
        }
       }
       return longest;
    }
};
