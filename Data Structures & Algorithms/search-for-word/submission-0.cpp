class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};
    int m, n;
    bool dfs(int i, int j, string cur, string word, vector<vector<char>>& board) {
        if (cur.size() == word.size()) {
            if (cur == word) {
                return true;
            } else {
                return false;
            }
        }
        for (int k = 0; k < 4; k++) {
            int newi = i + dir[k];
            int newj = j + dir[k + 1];
            if (newi >= 0 && newj >= 0 && newi < m && newj < n) {
                if (dfs(newi, newj, cur + board[i][j], word, board)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
       m = board.size();
       n = board[0].size();
       for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                   if (dfs(i, j, "", word, board)) {
                        return true;
                   }
                }
            }
       }
       return false;
    }
};
