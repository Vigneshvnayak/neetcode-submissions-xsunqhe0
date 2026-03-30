class Solution {
public:
    int n;
    bool dfs(int index, int target, vector<int>& sides, vector<int>& matchsticks) {
        if (index >= n) {
            if (sides[0] == target && sides[1] == target && sides[2] == target &&
                sides[3] == target) {
                    return true;
            }
        }
        for (int i = 0; i < 4; i++) {
            if (sides[i] + matchsticks[index] <= target) {
                sides[i] += matchsticks[index];
                if (dfs(index + 1, target, sides, matchsticks)) {
                    return true;
                }
                sides[i] -= matchsticks[index];
            }
            /*
            if (sides[i] == 0) {
                break;
            }
            */
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
       n = matchsticks.size();
       int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
       if (total % 4 != 0) return false;
       int target = total / 4;
       vector<int> sides(4, 0);
       return dfs(0, target, sides, matchsticks);
    }
};