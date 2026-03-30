class Solution {
public:
    void dfs(int index, int turn, int& alice, vector<int>& stoneValue) {
        if (index >= stoneValue.size()) {
            return;
        }
        for (int i = index; i < 3 && i < stoneValue.size(); i++) {
           alice += (turn & 1) ? 0 : stoneValue[i];
        }
        dfs(index + 3, turn + 1, alice, stoneValue);
        return;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int total = accumulate(stoneValue.begin(), stoneValue.end(), 0);
        int alice = 0;
        dfs(0, 0, alice, stoneValue);
        int bob = total - alice;
        if (alice > bob) {
            return "Alice";
        } else if (bob > alice) {
            return "Bob";
        }
        return "Tie";
    }
};