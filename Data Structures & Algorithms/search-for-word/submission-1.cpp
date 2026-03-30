class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};
    int m, n;
    bool dfs(int i, int j, int index, string word, vector<vector<char>>& board) {
        if (index == word.size()) {
            return true;
        }
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[index]) {
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '#';
        for (int k = 0; k < 4; k++) {
            int newi = i + dir[k];
            int newj = j + dir[k + 1];
            if (dfs(newi, newj, index + 1, word, board)) {
                return true;
            }
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
       m = board.size();
       n = board[0].size();
       for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(i, j, 0, word, board)) {
                    return true;
                }
            }
       }
       return false;
    }
};
