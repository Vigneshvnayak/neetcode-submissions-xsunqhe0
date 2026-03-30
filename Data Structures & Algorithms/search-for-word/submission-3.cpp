class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<int> dir = {0, 1, 0, -1, 0};
        queue<tuple<int,int,int>> q;
        for (int i = 0; i < m; i++) {
            for (int j =0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    char temp = board[i][j];
                    board[i][j] = '#';
                    q.push({i, j, 0});
                    while (!q.empty()) {
                        auto [i, j, index] = q.front();
                        q.pop();
                        if (index == word.size() - 1) {
                            return true;
                        }
                        for (int k = 0; k < 4; k++) {
                            int newi = i + dir[k];
                            int newj = j + dir[k + 1];
                            if (newi >= 0 && newj >= 0 && newi < m && newj < n &&
                            word[index + 1] == board[newi][newj]) {
                                q.push({newi, newj, index + 1});
                            }
                        }
                    }
                    board[i][j] = temp;
                }
            }
        }
        return false;
    }
};
