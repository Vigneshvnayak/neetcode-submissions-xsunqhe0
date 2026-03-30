class Solution {
public:
    void solve(vector<vector<char>>& board) {
       queue<pair<int, int>> q;
       int ROWS = board.size();
       int COLS = board[0].size();
       for (int i=0; i<ROWS; i++) {
        if (board[i][0] == 'O') {
            q.push({i, 0});
        }
        if (board[i][COLS-1] == 'O') {
            q.push({i, COLS-1});
        }
       }
       for (int i=0; i<COLS; i++) {
        if (board[0][i] == 'O') {
            q.push({0, i});
        }
        if (board[ROWS-1][i] == 'O') {
            q.push({ROWS-1, i});
        }
       }
       vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
       while (!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();
        int r = cur.first;
        int c = cur.second;
        board[r][c] = '#';
        for (vector<int> &d : dir) {
            int nr = r + d[0];
            int nc = c + d[1];
            if (nr >=0 && nc >=0 && nr < ROWS && nc < ROWS && 
            board[nr][nc] == 'O') {
                q.push({nr,nc});
            }
          }
       }
       for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
            if (board[i][j] == '#') {
                board[i][j] = 'O';
            }
         }
       }
    }
};
