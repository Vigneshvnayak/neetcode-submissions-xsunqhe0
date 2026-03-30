class Solution {
public:
    bool dfs(int index, int target, vector<int>& sides, vector<int>& ms) {
        if (index == ms.size()) {
            return (sides[0] == target && sides[1] == target && sides[2] == target && sides[3] == target);
        }
        for (int i = 0; i < 4; i++) {
            if (sides[i] + ms[index] <= target) {
                sides[i] += ms[index];
                if (dfs(index + 1, target, sides, ms)) {
                    return true;
                }
                sides[i] -= ms[index];
            }
            if (sides[i] == 0) {
                break;
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (total % 4 != 0) {
            return false;
        }
        sort(matchsticks.rbegin(), matchsticks.rend());
        int target = total / 4;
        vector<int> sides(4, 0);
        return dfs(0, target, sides, matchsticks);
    }
};