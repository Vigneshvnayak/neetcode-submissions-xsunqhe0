class Solution {
public:
    vector<vector<string>> res;
    void dfs(int r, int n, vector<int>& pd, vector<int>& nd, vector<int>& col, vector<string>& board) {
        if (r == n) { 
            res.push_back(board);
            return;
        }
        for (int c = 0; c < n; c++) {
            if (pd[r + c] || nd[r - c + n] || col[c]) continue;
            col[c] = 1;
            pd[r + c] = 1;
            nd[r - c + n] = 1;
            board[r][c] = 'Q';
            dfs(r + 1, n, pd, nd, col, board);
            board[r][c] = '.';
            pd[r + c] = 0;
            nd[r - c + n] = 0;
            col[c] = 0;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<int> pd(2 * n, 0);
        vector<int> nd(2 * n, 0);
        vector<int> col(n, 0);
        dfs(0, n, pd, nd, col, board);
        return res;
    }
};
